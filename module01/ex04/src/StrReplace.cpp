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
	std::string new_s;

	for (size_t i = 0; i < s.length(); i++) {
		if (s.substr(i).find("\\n") == 0) {
			i++;
			new_s += "\n";
		}
		else
			new_s += s[i];
	}
	s.clear();
	s = new_s;
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
	outfile << this->replaceOccurrences(infile_full);
	outfile.close();
	this->print_result();
	return true;
}

std::string	StrReplace::replaceOccurrences(std::string& s) {
	std::string	new_s;
	int	find_len = this->to_find.length();
	
	for (size_t i = 0; i < s.length(); i++) {
		if (s.substr(i).find(this->to_find) == 0) {
			i += find_len - 1;
			new_s += this->to_insert;
			this->found++;
		}
		else
			new_s += s[i];
	}
	return new_s;
}

void	StrReplace::print_result() {
	std::cout	<< this->found << " instances of: " << "\"" + this->to_find + "\""
				<< " were found and replaced with: " << "\"" + this->to_insert + "\""
				<< std::endl;
}
