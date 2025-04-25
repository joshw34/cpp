#include "../inc/PhoneBook.hpp"

void	press_enter(std::string err_msg, bool flush_input) {
	if (flush_input == true) {
		std::cin.clear();  // Clear error flags
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}
	if (err_msg.empty() == false) {
		system("clear");
	std::cerr << RED << err_msg << RESET << "\n\n";
	}
	std::cout << "Press " << GREEN << "ENTER " << RESET << "to continue" << std::endl;
	std::getchar();
	system("clear");
}

static	bool	is_only_whitespace(std::string &input) {
	if (input.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
		return true;
	return false;
}

static	bool	is_valid_number(std::string &input) {
	if (input.find_first_not_of("0123456789") == std::string::npos)
		return true;
	else
		return false;
}

bool	is_valid_input(std::string &input, const std::string &var) {
	std::cout << "Enter " << GREEN << var << RESET << ":\n> ";
	std::getline(std::cin, input);
	if (input.empty() == true || is_only_whitespace(input) == true) {
		press_enter("Invalid Input. Please enter a value", false);
		return false;
	}
	if (var.compare("Phone Number") == 0 && is_valid_number(input) == false) {
		press_enter("Invalid Phone Number. Try again", false);
		return false;
	}
	system("clear");
	return true;
}

bool	is_valid_index(int &c_ind, std::string &input, int &total) {
	
	std::cout << "\nEnter " << GREEN << "index " << RESET << "number to view contact details or ";
	std::cout << GREEN << "X" << RESET << " to return to main menu\n" << std::endl << "> ";
	std::cin >> input;
	if (input.length() == 1 && is_valid_number(input) == true && input[0] - 48 <= total-1) {
		c_ind = input[0] - 48;
		return true;
	}
	else if (input.compare("X") == 0)
		return true;
	else {
		press_enter("Invalid Input: Enter index number or X\n", true);
		return false;
	}
}
