#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

Form::Form() : name("defaultForm"), signedStatus(false),
    signingGrade(MAX_GRADE), execGrade(MAX_GRADE) {
  std::cout << BOLD << "Default Form Constructor called" << RESET << std::endl;
}

Form::Form(const std::string name, const int signingGrade, const int execGrade)
    : name(name), signedStatus(false), signingGrade(signingGrade),
      execGrade(execGrade) {
  std::cout << BOLD << "Form Constructor called for " << name << RESET
            << std::endl;

  if (signingGrade < MAX_GRADE || execGrade < MAX_GRADE)
    throw GradeTooHighException();
  else if (signingGrade > MIN_GRADE || execGrade > MIN_GRADE)
    throw GradeTooLowException();
}

Form::Form(const Form& src) : name(src.getName()),
    signedStatus(src.getSignedStatus()), signingGrade(src.getSigningGrade()),
    execGrade(src.getExecGrade()) {
  std::cout << BOLD << "Form Copy Constructor called for " << name << RESET
            << std::endl;
}

Form::~Form() {
  std::cout << BOLD << "Form Destructor called for " << name << RESET
            << std::endl;
}

Form& Form::operator=(const Form&) {
  // Nothing to copy
  return *this;
}

const std::string& Form::getName() const {
  return this->name;
}

bool Form::getSignedStatus() const {
  return this->signedStatus;
}

int Form::getSigningGrade() const {
  return this->signingGrade;
}

int Form::getExecGrade() const {
  return this->execGrade;
}

void Form::beSigned(const Bureaucrat& b) {
  if (this->signingGrade < b.getGrade())
    throw GradeTooLowException();
  this->signedStatus = true;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Error: Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Error: Grade Too Low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
  os << std::boolalpha << "Form Name: " << f.getName() << "\n"
     << "Signed: " << f.getSignedStatus() << "\n"
     << "Signing Grade: " << f.getSigningGrade() << "\n"
     << "Execution Grade: " << f.getExecGrade() << std::noboolalpha;
  return os;
}
