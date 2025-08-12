#pragma once

#include <exception>
#include <iostream>  // IWYU pragma: keep
#include <ostream>
#include <string>

#include "../inc/Colors.hpp"  // IWYU pragma: keep

class AForm;

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const std::string name, const int grade);
  Bureaucrat(const Bureaucrat& src);
  ~Bureaucrat();

  Bureaucrat& operator=(const Bureaucrat& src);

  int getGrade() const;
  const std::string& getName() const;
  void incGrade();
  void decGrade();

  void signForm(AForm& f) const;
  void executeForm(const AForm& form) const;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

 private:
  const std::string name;
  int grade;
  static const int MAX_GRADE = 1;
  static const int MIN_GRADE = 150;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
