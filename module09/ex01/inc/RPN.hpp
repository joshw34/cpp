#pragma once

#include <cstdlib>
#include <iostream>  // IWYU pragma: keep
#include <stack>
#include <stdexcept>  // IWYU pragma: keep
#include <string>

class RPN {
 public:
  RPN(const std::string&);
  ~RPN();

  void solve();

 private:
  RPN();
  RPN(const RPN&);
  RPN& operator=(const RPN&);

  std::string input;
  std::stack<double> operands;

  bool isOperator(const char) const;
  void calculate(const char);
};
