#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"

int	main(void)
{
	Contact	new_contact;
	std::string	input;
	std::cout << "Enter Name" << std::endl;
	std::getline(std::cin, input);
	new_contact.setName(input);
	std::cout << "Enter LastName" << std::endl;
	std::getline(std::cin, input);
	new_contact.setLast(input);
	std::cout << "Enter NickName" << std::endl;
	std::getline(std::cin, input);
	new_contact.setNick(input);
	std::cout << "Enter Phone Number" << std::endl;
	std::getline(std::cin, input);
	new_contact.setPhone(input);
	std::cout << "Enter Darkest Secret" << std::endl;
	std::getline(std::cin, input);
	new_contact.setSecret(input);
	system("clear");
	std::cout << std::setw(5) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "Name: " << new_contact.getName() << std::endl;
	std::cout << "LastName: " << new_contact.getLast() << std::endl;
	std::cout << "NickName: " << new_contact.getNick() << std::endl;
	std::cout << "Phone No.: " << new_contact.getPhone() << std::endl;
	std::cout << "Darkest Secret:" << new_contact.getSecret() << std::endl;
	return (0);
}
