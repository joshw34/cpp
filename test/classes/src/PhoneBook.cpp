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

bool	is_valid_index(int &input, int total) {
	std::cout << "Enter " << GREEN << "index " << RESET << "number to view contact details or ";
	std::cout << GREEN << "9" << RESET << " to return to main menu\n" << ">";
	std::cin >> input;
	if (input < 0 || input > 9 || ((input > total - 1) && input != 9)) {
		std::cin.clear();  // Clear error flags
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard bad input
		std::cerr << RED << "Invalid Input: Enter index number or 9\n" << RESET;
		return (false);
	}
	return (true);
}

void	PhoneBook::find_contact() {
	std::string	name, last, nick;
	int	input = 42;

	system("clear");
	if (total == 0) {
		std::cerr << RED << "Error: No contacts found: Please add a contact" << RESET;
		return;
	}
	std::cout << "|" << BOLD << std::setw(10) << "Index" << RESET << "|";
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
		std::cout << "|" << GREEN << std::setw(10) << index << RESET << "|";
		std::cout << std::setw(10) << name << "|";
		std::cout << std::setw(10) << last << "|";
		std::cout << std::setw(10) << nick << "|" << std::endl;
		index++; 
	}
	while (is_valid_index(input, total) == false) {};
	if (input == 9)
		return ;
	else {
		system("clear");
		std::cout << BOLD << "First Name:     " << RESET << data[input].getName() << "\n";
		std::cout << BOLD << "Last Name:      " << RESET << data[input].getLast() << "\n";
		std::cout << BOLD << "Nick Name:      " << RESET << data[input].getNick() << "\n";
		std::cout << BOLD << "Phone Number:   " << RESET << data[input].getPhone() << "\n";
		std::cout << BOLD << "Darkest Secret: " << RESET << data[input].getSecret() << "\n" << std::endl;
	}
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // flush input buffer
	std::cout << "Press " << GREEN << "ENTER " << RESET << "to return to main menu" << std::endl;
	std::getchar();
}
