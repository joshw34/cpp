#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"

int	main(void)
{
	PhoneBook	PBook;
	std::string	input;

	while (1) {
		system("clear");
		std::cout << BOLD << "PhoneBook\n" << RESET;
		std::cout << GREEN << "ADD " << RESET << "a contact. ";
		std::cout << GREEN << "SEARCH " << RESET << "for a contact. ";
		std::cout << GREEN << "EXIT " << RESET << "application." << std::endl;
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			PBook.add_contact();
		else if (input.compare("SEARCH") == 0)
			PBook.find_contact();
		else if (input.compare("EXIT") == 0)
			break ;
	}
	return (0);
}
