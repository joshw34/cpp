#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

#include "./Contact.hpp"
#include <iostream> // IWYU pragma: keep
#include <iomanip> // IWYU pragma: keep
#include <limits> // IWYU pragma: keep
#include <string>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>


class	PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

        void run();

	private:
		int total;
		int index;
		Contact data[8];

		void addContact();
		void findContact();
		void listContacts();

        bool isValidInput(std::string &input, const std::string &var);
        bool isValidIndex(int &c_ind, std::string &input, int &total);
        void pressEnter(std::string err_msg, bool flush_input);
        bool isOnlyWhitespace(std::string &input);
        bool isValidNumber(std::string &input);
};

#endif
