#include "../inc/StrReplace.hpp"

StrReplace::StrReplace() {}

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

bool	StrReplace::setStrings(char* to_find, char* to_replace) {
	if (!to_find || !to_replace) {
		std::cerr << "Error: Search and Replace strings are required" << std::endl;
		return false;
	}
	this->to_find = to_find;
	this->to_replace = to_replace;
	if (this->to_find.empty()) {
		std::cerr << "Error: Search string must not be empty" << std::endl;
		return false;
	}
	return true;
}


