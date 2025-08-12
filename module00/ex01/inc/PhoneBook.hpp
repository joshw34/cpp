#pragma once

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <iomanip>   // IWYU pragma: keep
#include <iostream>  // IWYU pragma: keep
#include <limits>    // IWYU pragma: keep
#include <string>

#include "./Contact.hpp"
#include "Colors.hpp"  // IWYU pragma: keep

class PhoneBook {
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

  bool isValidInput(std::string& input, const std::string& var);
  bool isValidIndex(int& c_ind, std::string& input, int& total);
  void pressEnter(std::string err_msg, bool flush_input);
  bool isOnlyWhitespace(std::string& input);
  bool isValidNumber(std::string& input);
};
