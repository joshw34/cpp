#include <errno.h>

#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "../inc/Colors.hpp"
#include "../inc/PmergeMe.hpp"

static long validateValue(const std::string& arg) {
  errno = 0;
  char* end;
  long value = std::strtol(arg.c_str(), &end, 10);
  if (errno == ERANGE)
    throw std::invalid_argument("Number too large (overflow)");
  if (*end != '\0')
    throw std::invalid_argument("Invalid number format");
  if (value > std::numeric_limits<int>::max())
    throw std::invalid_argument("Provided argument > INT_MAX");
  return value;
}

static void validateFormat(const std::string& arg) {
  if (arg.find_first_of("1234567890") == arg.npos)
    throw std::invalid_argument("Argument with 0 digits");
  if (arg.find_first_not_of("1234567890+-") != arg.npos)
    throw std::invalid_argument("Invalid character in input");
  if (arg.at(0) == '-')
    throw std::invalid_argument("Negative number in input");
  if (arg.find_first_of("-") != arg.npos)
    throw std::invalid_argument("Invalid character in input");
  if (arg.substr(1).find_first_of("+") != arg.npos)
    throw std::invalid_argument("Multiple/Incorrect positioning of '+'");
}

static std::string isValidString(char* arg) {
  if (arg[0] == '\0')
    throw std::invalid_argument("Empty String in Input");
  return arg;
}

std::vector<int> getInput(char** args) {
  std::vector<int> input;
  for (size_t i = 0; args[i]; ++i) {
    std::string str_value = isValidString(args[i]);
    validateFormat(str_value);
    long value = validateValue(str_value);
    input.push_back(static_cast<int>(value));
  }
  return input;
}

int main(int ac, char** av) {
  if (ac < 2) {
    std::cerr << RED << "Error: Invalid number of arguments\n" << RESET;
    return EXIT_FAILURE;
  }
  try {
    std::vector<int> input = getInput(av + 1);
    PmergeMe test(input);
    test.sort();
  } catch (const std::exception& e) {
    std::cerr << RED << "Error: " << e.what() << "\n" << RESET;
    return EXIT_FAILURE;
  }
}
