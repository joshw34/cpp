#pragma once

#include <exception>
#include <iostream>  // IWYU pragma: keep
#include <ostream>
#include <string>

#include "../inc/Colors.hpp"  // IWYU pragma: keep

class Bureaucrat;

class Form {
 public:
  Form();
  Form(std::string name, int signingGrade, int execGrade);
  Form(const Form& src);
  ~Form();

  Form& operator=(const Form& src);

  const std::string& getName() const;
  bool getSignedStatus() const;
  int getSigningGrade() const;
  int getExecGrade() const;

  void beSigned(const Bureaucrat& b);

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
  bool signedStatus;
  const int signingGrade;
  const int execGrade;
  static const int MAX_GRADE = 1;
  static const int MIN_GRADE = 150;
};

std::ostream& operator<<(std::ostream& os, const Form& f);
