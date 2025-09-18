#pragma once

#include <cstdlib>
#include <iostream>  // IWYU pragma: keep
#include <stack>
#include <stdexcept>  // IWYU pragma: keep
#include <string>

class RPN {
 public:
  RPN(const std::string&);
  RPN(const RPN&);
  ~RPN();

  RPN& operator=(const RPN&);

  void run();

 private:
  RPN();  // Private so it isn't used

  std::string input;
  std::stack<int> operands;

  bool isOperator(const char) const;
  void calculate(const char);
};
