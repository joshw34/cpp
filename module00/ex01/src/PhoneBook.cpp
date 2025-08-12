#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook() {
  total = 0;
  index = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::run() {
  bool quit = false;
  std::string input;

  while (quit == false) {
    system("clear");
    std::cout << BOLD << "PhoneBook\n" << RESET;
    std::cout << GREEN << "ADD " << RESET << "a contact. ";
    std::cout << GREEN << "SEARCH " << RESET << "for a contact. ";
    std::cout << GREEN << "EXIT " << RESET << "application." << std::endl;
    std::cout << "> ";

    std::getline(std::cin, input);

    if (input.compare("ADD") == 0)
      addContact();
    else if (input.compare("SEARCH") == 0)
      findContact();
    else if (input.compare("EXIT") == 0)
      quit = true;
  }
}

void PhoneBook::addContact() {
  std::string input;

  if (index == 8)
    index = 0;
  system("clear");
  while (isValidInput(input, "First Name") == false) {
  };
  data[index].setName(input);
  while (isValidInput(input, "Last Name") == false) {
  };
  data[index].setLast(input);
  while (isValidInput(input, "Nickname") == false) {
  };
  data[index].setNick(input);
  while (isValidInput(input, "Phone Number") == false) {
  };
  data[index].setPhone(input);
  while (isValidInput(input, "Darkest Secret") == false) {
  };
  data[index].setSecret(input);
  index++;
  if (total < 8)
    total++;
}

void PhoneBook::findContact() {
  int c_ind = 42;
  std::string input;

  system("clear");
  if (total == 0)
    return pressEnter("Error: No contacts found: Please add a contact", false);

  do {
    listContacts();
  } while (isValidIndex(c_ind, input, total) == false);

  if (input.compare("X") == 0) {
    return;
  } else {
    system("clear");
    std::cout << BOLD << "First Name:     " << RESET << data[c_ind].getName()
              << "\n";
    std::cout << BOLD << "Last Name:      " << RESET << data[c_ind].getLast()
              << "\n";
    std::cout << BOLD << "Nick Name:      " << RESET << data[c_ind].getNick()
              << "\n";
    std::cout << BOLD << "Phone Number:   " << RESET << data[c_ind].getPhone()
              << "\n";
    std::cout << BOLD << "Darkest Secret: " << RESET << data[c_ind].getSecret()
              << "\n"
              << std::endl;
  }

  pressEnter("", true);
}

void PhoneBook::listContacts() {
  std::string name, last, nick;
  int i = 0;

  system("clear");
  std::cout << "|" << BOLD << std::setw(10) << "Index" << RESET << "|";
  std::cout << BOLD << std::setw(10) << "Firstname" << RESET << "|";
  std::cout << BOLD << std::setw(10) << "Lastname" << RESET << "|";
  std::cout << BOLD << std::setw(10) << "Nickname" << RESET << "|" << std::endl;
  i = 0;
  while (i < 8) {
    if (i == total)
      break;
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

bool PhoneBook::isValidInput(std::string& input, const std::string& var) {
  std::cout << "Enter " << GREEN << var << RESET << ":\n> ";
  std::getline(std::cin, input);
  if (input.empty() == true || isOnlyWhitespace(input) == true) {
    pressEnter("Invalid Input. Please enter a value", false);
    return false;
  }
  if (var.compare("Phone Number") == 0 && isValidNumber(input) == false) {
    pressEnter("Invalid Phone Number. Try again", false);
    return false;
  }
  system("clear");
  return true;
}

bool PhoneBook::isValidIndex(int& c_ind, std::string& input, int& total) {
  std::cout << "\nEnter " << GREEN << "index " << RESET
            << "number to view contact details or ";
  std::cout << GREEN << "X" << RESET << " to return to main menu\n"
            << std::endl
            << "> ";
  std::cin >> input;
  if (input.length() == 1 && isValidNumber(input) == true &&
      input[0] - 48 <= total - 1) {
    c_ind = input[0] - 48;
    return true;
  } else if (input.compare("X") == 0)
    return true;
  else {
    pressEnter("Invalid Input: Enter index number or X\n", true);
    return false;
  }
}

void PhoneBook::pressEnter(std::string err_msg, bool flush_input) {
  if (flush_input == true) {
    std::cin.clear();  // Clear error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  if (err_msg.empty() == false) {
    system("clear");
    std::cerr << RED << err_msg << RESET << "\n\n";
  }
  std::cout << "Press " << GREEN << "ENTER " << RESET << "to continue"
            << std::endl;
  std::getchar();
  system("clear");
}

bool PhoneBook::isOnlyWhitespace(std::string& input) {
  if (input.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
    return true;
  return false;
}

bool PhoneBook::isValidNumber(std::string& input) {
  if (input.find_first_not_of("0123456789") == std::string::npos)
    return true;
  else
    return false;
}
