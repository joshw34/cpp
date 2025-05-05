#include "../inc/StrReplace.hpp"

StrReplace::StrReplace() {
	this->found = 0;
}

StrReplace::~StrReplace() {}

bool	StrReplace::setInfile(char* filename) {
	if (!filename) {
		std::cerr << "Error: No input file provided" << std::endl;
		return false;
	}
	this->infile = filename;
	if (this->infile.empty()) {
		std::cerr << "Error: No input file provided" << std::endl;
		return false;
	}
	std::ifstream file(this->infile.c_str());
	if (!file.good()) {
		std::cerr << "Error: Unable to open input file" << std::endl;
		return false;
	}
	this->outfile = this->infile + ".replace";
	return true;
}

bool	StrReplace::setStrings(char* to_find, char* to_insert) {
	if (!to_find || !to_insert) {
		std::cerr << "Error: Search and Replace strings are required" << std::endl;
		return false;
	}
	this->to_find = to_find;
	this->to_insert = to_insert;
	if (this->to_find.empty()) {
		std::cerr << "Error: Search string must not be empty" << std::endl;
		return false;
	}
	this->replaceNewlineChar(this->to_find);
	this->replaceNewlineChar(this->to_insert);
	return true;
}

void	StrReplace::replaceNewlineChar(std::string& s) {
	size_t	i = 0;
	while (1) {
		i = s.find("\\n", i);
		if (i == s.npos)
			return ;
		s.erase(i, 2);
		s.insert(i, "\n");
		i++;
	}
}

bool	StrReplace::replace() {
	std::ifstream infile(this->infile.c_str());
	std::ofstream outfile(this->outfile.c_str());
	std::stringstream buffer;
	std::string	infile_full;
	
	if (!outfile.is_open()) {
		std::cerr << "Error: could not open output file";
		return false;
	}
	if (!infile.is_open()) {
		std::cerr << "Error: could not open input file";
		return false;
	}
	buffer << infile.rdbuf();
	infile_full = buffer.str();
	infile.close();
	this->replaceOccurrences(infile_full);
	outfile << infile_full;
	outfile.close();
	this->print_result();
	return true;
}

void	StrReplace::replaceOccurrences(std::string& s) {
	size_t	i = 0;
	
	while (1) {
		i = s.find(this->to_find, i);
		if (i == s.npos)
			return ;
		s.erase(i, this->to_find.length());
		s.insert(i, this->to_insert);
		i += this->to_insert.length();
		this->found++;
	}
}

void	StrReplace::print_result() {
	std::cout	<< this->found << " instances of: " << "\"" + this->to_find + "\""
				<< " were found and replaced with: " << "\"" + this->to_insert + "\""
				<< std::endl;
}
