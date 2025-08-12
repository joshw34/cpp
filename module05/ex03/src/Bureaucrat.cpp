#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(MIN_GRADE) {
  std::cout << BOLD << "Default Bureaucrat Constructor Called" << RESET
            << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : name(name) {
  std::cout << BOLD << "Bureaucrat Constructor Called for " << name << RESET
            << std::endl;

  if (grade < MAX_GRADE)
    throw GradeTooHighException();
  else if (grade > MIN_GRADE)
    throw GradeTooLowException();

  this->grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name(src.getName()), grade(src.getGrade()) {
  std::cout << BOLD << "Bureaucrat Copy Constructor Called to copy " << name
            << RESET << std::endl;
};

Bureaucrat::~Bureaucrat() {
  std::cout << BOLD << "Bureaucrat Destructor Called for " << name << RESET
            << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
  if (this != &src) {
    this->grade = src.getGrade();
  }
  return *this;
}

int Bureaucrat::getGrade() const {
  return this->grade;
}

const std::string& Bureaucrat::getName() const {
  return this->name;
}

void Bureaucrat::incGrade() {
  if (grade == MAX_GRADE)
    throw GradeTooHighException();
  this->grade--;
}

void Bureaucrat::decGrade() {
  if (grade == MIN_GRADE)
    throw GradeTooLowException();
  this->grade++;
}

void Bureaucrat::signForm(AForm& f) const {
  try {
    f.beSigned(*this);
    std::cout << GREEN << name << " signed " << f.getName() << RESET
              << std::endl;
  } catch (std::exception& e) {
    std::cout << RED << name << " couldn't sign " << f.getName()
              << " because their grade is too low" << RESET << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm& form) const {
  try {
    form.execute(*this);
    std::cout << GREEN << name << " executed " << form.getName() << RESET
              << std::endl;
  } catch (std::exception& e) {
    std::cout << RED << name << " cannot execute " << form.getName() << ": "
              << e.what() << RESET << std::endl;
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Error: Grade must not be below 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Error: Grade must not be above 150";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return os;
}
