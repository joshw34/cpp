#ifndef STRREPLACE_HPP
#define STRREPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class	StrReplace {
	public:
		StrReplace();
		~StrReplace();

		bool	setInfile(char* filename);
		bool	setStrings(char* to_find, char* to_replace);

	private:
		std::string infile;
		std::string	outfile;
		std::string	to_find;
		std::string to_replace;
};

#endif
