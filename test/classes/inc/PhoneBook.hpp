#ifndef PHONE_BOOK_CPP
#define PHONE_BOOK_CPP

#include "./Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>

class	PhoneBook
{
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
