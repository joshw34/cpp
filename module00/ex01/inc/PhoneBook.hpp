#ifndef PHONE_BOOK_CPP
#define PHONE_BOOK_CPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

#include "./Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

bool	is_valid_input(std::string &input, const std::string &var);
bool	is_valid_index(int &c_ind, std::string &input, int &total);
void	press_enter(std::string err_msg, bool flush_input);

class	PhoneBook {
	private:
		int		total;
		int		index;
		void	list_contacts();
		Contact data[8];

	
	public:
		PhoneBook();
		~PhoneBook();

		void	add_contact();
		void	find_contact();
};

#endif
