#pragma once

#include <iostream>  // IWYU pragma: keep
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"  // IWYU pragma: keep

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& src);
  ~PresidentialPardonForm();

  PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

  const std::string& getTarget() const;

  void executeAction() const;

 private:
  std::string target;
};
