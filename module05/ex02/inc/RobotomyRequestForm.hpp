#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>  // IWYU pragma: keep
#include <string>

#include "../inc/Colors.hpp"  // IWYU pragma: keep
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& src);
  ~RobotomyRequestForm();

  RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

  const std::string& getTarget() const;

  void executeAction() const;

 private:
  std::string target;
  static bool seeded;
  static void seedRand();
};
