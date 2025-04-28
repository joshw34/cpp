#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook() {
	total = 0;
	index = 0;
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::add_contact() {
	std::string	input;
	
	if (index == 8)
		index = 0;
	system("clear");
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
	index++;
	if (total < 8)
		total++;
}

void	PhoneBook::list_contacts() {
	std::string	name, last, nick;
	int	i = 0;
	
	system("clear");
	std::cout << "|" << BOLD << std::setw(10) << "Index" << RESET << "|";
	std::cout << BOLD << std::setw(10) << "Firstname" << RESET << "|";
	std::cout << BOLD << std::setw(10) << "Lastname" << RESET << "|";
	std::cout << BOLD << std::setw(10) << "Nickname" << RESET << "|" << std::endl;
	i = 0;
	while (i < 8) {
		if (i == total)
			break ;
		name = data[i].getName();
		if (name.length() > 9)
			name = name.substr(0, 9) + ".";
		last = data[i].getLast();
		if (last.length() > 9)
			last = last.substr(0, 9) + ".";
		nick = data[i].getNick();
		if (nick.length() > 9)
			nick = nick.substr(0, 9) + ".";
		std::cout << "|" << GREEN << std::setw(10) << i << RESET << "|";
		std::cout << std::setw(10) << name << "|";
		std::cout << std::setw(10) << last << "|";
		std::cout << std::setw(10) << nick << "|" << std::endl;
		i++; 
	}
}

void	PhoneBook::find_contact() {
	int	c_ind = 42;
	std::string input;

	system("clear");
	if (total == 0)
		return press_enter("Error: No contacts found: Please add a contact", false);
	do {
		PhoneBook::list_contacts();
	}	while (is_valid_index(c_ind, input, total) == false);
	if (input.compare("X") == 0) {
		return ;
	}
	else {
		system("clear");
		std::cout << BOLD << "First Name:     " << RESET << data[c_ind].getName() << "\n";
		std::cout << BOLD << "Last Name:      " << RESET << data[c_ind].getLast() << "\n";
		std::cout << BOLD << "Nick Name:      " << RESET << data[c_ind].getNick() << "\n";
		std::cout << BOLD << "Phone Number:   " << RESET << data[c_ind].getPhone() << "\n";
		std::cout << BOLD << "Darkest Secret: " << RESET << data[c_ind].getSecret() << "\n" << std::endl;
	}
	press_enter("", true);
}
