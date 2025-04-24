#ifndef PHONE_BOOK_CPP
#define PHONE_BOOK_CPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

#include "./Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>

class	PhoneBook {
	private:
		int		total;
		int		index;
		Contact data[8];
	
	public:
		PhoneBook();
		~PhoneBook();

		void	add_contact();
		void	find_contact();
};

#endif
