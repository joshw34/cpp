#include "../inc/RPN.hpp"

RPN::RPN() {}  // Private

RPN::RPN(const std::string& input) : input(input) {}

RPN::RPN(const RPN& src) : input(src.input), operands(src.operands) {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& src) {
  if (this != &src) {
    this->input = src.input;
    this->operands = src.operands;
  }
  return *this;
}

void RPN::run() {
  for (size_t i = 0; i < input.size(); ++i) {
    char c = input.at(i);
    bool next_is_space = (i + 1 == input.size() || input.at(i + 1) == ' ') ? true : false;
    if (c == ' ' && !next_is_space)
      continue;
    else if (std::isdigit(c) && next_is_space)
      operands.push(c - 48);
    else if (isOperator(c) && next_is_space)
      calculate(c);
    else
      throw std::invalid_argument("Invalid Characters / Format");
  }
  if (operands.size() != 1)
    throw std::invalid_argument(
        "Too many operands (n operands = n-1 operators)");
  std::cout << operands.top() << std::endl;
}

bool RPN::isOperator(const char c) const {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::calculate(const char operation) {
  if (operands.size() < 2)
    throw std::invalid_argument(
        "Too many operators (n operands = n-1 operators)");
  int right = operands.top();
  operands.pop();
  int left = operands.top();
  operands.pop();
  switch (operation) {
    case '+':
      operands.push(left + right);
      break;
    case '-':
      operands.push(left - right);
      break;
    case '*':
      operands.push(left * right);
      break;
    case '/':
      if (right == 0)
        throw std::invalid_argument("Division by 0");
      operands.push(left / right);
      break;
  }
}
