#include "../inc/ScalarConverter.hpp"

int ScalarConverter::input_type = -1;
char ScalarConverter::c_val = 0;
double ScalarConverter::p_val = 0;
int ScalarConverter::i_val = 0;
float ScalarConverter::f_val = 0;
double ScalarConverter::d_val = 0;

void ScalarConverter::convert(const std::string& input) {
  if (input.empty())
    throw InvalidType();
  getInputType(input);
  printResult[input_type]();
}

const char* ScalarConverter::InvalidType::what() const throw() {
  return "Error: Invalid Type";
}

const char* ScalarConverter::Overflow::what() const throw() {
  return "Error: Overflow";
}
