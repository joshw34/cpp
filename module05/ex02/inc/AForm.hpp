#pragma once

#include <exception>
#include <iostream>  // IWYU pragma: keep
#include <string>

#include "../inc/Colors.hpp"  // IWYU pragma: keep

class Bureaucrat;

class AForm {
 public:
  AForm();
  AForm(std::string name, int signingGrade, int execGrade);
  AForm(const AForm& src);
  virtual ~AForm();

  AForm& operator=(const AForm& src);

  const std::string& getName() const;
  bool getSignedStatus() const;
  int getSigningGrade() const;
  int getExecGrade() const;

  void beSigned(const Bureaucrat& b);

  void execute(const Bureaucrat& executor) const;
  virtual void executeAction() const = 0;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

  class FormNotSignedException : public std::exception {
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

std::ostream& operator<<(std::ostream& os, const AForm& f);
