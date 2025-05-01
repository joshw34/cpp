#ifndef STRREPLACE_HPP
#define STRREPLACE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>

class	StrReplace {
	public:
		StrReplace();
		~StrReplace();

		bool	setInfile(char* filename);
		bool	setStrings(char* to_find, char* to_insert);
		bool	replace();

	private:
		int			found;
		std::string infile;
		std::string	outfile;
		std::string	to_find;
		std::string to_insert;

		void		replaceNewlineChar(std::string& s);
		std::string replaceOccurrences(std::string& infile_full);
		void		print_result();
};

#endif
