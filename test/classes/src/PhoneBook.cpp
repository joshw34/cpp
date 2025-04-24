#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook() {
	total = 0;
	index = 0;
}

PhoneBook::~PhoneBook() {
}

static	bool	is_only_whitespace(std::string &input) {
	if (input.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
		return (true);
	else
		return (false);
}

static	bool	is_valid_number(std::string &input) {
	if (input.find_first_not_of("0123456789") == std::string::npos)
		return (true);
	else
		return (false);
}

static	bool	is_valid_input(std::string &input, const std::string &var) {
	std::cout << "Enter " << GREEN << var << RESET << ":\n> ";
	std::getline(std::cin, input);
	if (input.empty() == true || is_only_whitespace(input) == true)
		return (std::cout << RED << "\n" << var << " is required. Try again\n" << RESET << std::endl, false);
	if (var.compare("Phone Number") == 0 && is_valid_number(input) == false)
		return (std::cout << "\nInvalid Phone Number. Try again\n" << std::endl, false);
	system("clear");
	return (true);
}

void	PhoneBook::add_contact() {
	std::string	input;
	
	if (total < 8) {
		index = total;
		total++;
	}
	else {
		index = total % 8;
		total++;
	}
	system("clear");
	std::cout << index << " " << total << std::endl;
	while (is_valid_input(input, "First Name") == false) {};
	data[index].setName(input);
	while (is_valid_input(input, "Last Name") == false) {};
	data[index].setLast(input);
	while (is_valid_input(input, "Nickname") == false) {};
	data[index].setNick(input);
	while (is_valid_input(input, "Phone Number") == false) {};
	data[index].setPhone(input);
	while (is_valid_input(input, "Darkest Secret") == false) {};
	data[index].setSecret(input);
}

void	PhoneBook::find_contact() {
	std::string	name, last, nick;

	system("clear");
	if (total == 0) {
		std::cout << "Error: No contacts found: Please add a contact" << std::endl;
		return;
	}
	std::cout << BOLD << std::setw(10) << "Index" << RESET << "|";
	std::cout << BOLD << std::setw(10) << "Firstname" << RESET << "|";
	std::cout << BOLD << std::setw(10) << "Lastname" << RESET << "|";
	std::cout << BOLD << std::setw(10) << "Nickname" << RESET << "|" << std::endl;
	index = 0;
	while (index < 8) {
		if (index == total)
			break ;
		name = data[index].getName();
		if (name.length() > 9)
			name = name.substr(0, 9) + ".";
		last = data[index].getLast();
		if (last.length() > 9)
			last = last.substr(0, 9) + ".";
		nick = data[index].getNick();
		if (nick.length() > 9)
			nick = nick.substr(0, 9) + ".";
		std::cout << GREEN << std::setw(10) << index << RESET << "|";
		std::cout << std::setw(10) << name << "|";
		std::cout << std::setw(10) << last << "|";
		std::cout << std::setw(10) << nick << "|";
		index++; 
	}
	std::string pause;
	std::cin >> pause;
}
