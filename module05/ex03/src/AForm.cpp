#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : name("defaultForm"), signedStatus(false), signingGrade(MAX_GRADE), execGrade(MAX_GRADE) {
    std::cout << BOLD << "Default Form Constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string name, const int signingGrade, const int execGrade) : name(name), signedStatus(false), signingGrade(signingGrade), execGrade(execGrade) {
    std::cout << BOLD << "Form Constructor called for " << name << RESET << std::endl;

    if (signingGrade < MAX_GRADE || execGrade < MAX_GRADE)
        throw GradeTooHighException();
    else if (signingGrade > MIN_GRADE || execGrade > MIN_GRADE)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& src) : name(src.getName()), signedStatus(src.getSignedStatus()), signingGrade(src.getSigningGrade()), execGrade(src.getExecGrade()) {
    std::cout << BOLD << "Form Copy Constructor called for " << name << RESET << std::endl;
}

AForm::~AForm() {
    std::cout << BOLD << "Form Destructor called for " << name << RESET << std::endl;
}

AForm& AForm::operator=(const AForm&) {
    //Nothing to copy
    return *this;
}

const std::string& AForm::getName() const {
    return this->name;
}

bool AForm::getSignedStatus() const {
    return this->signedStatus;
}

int AForm::getSigningGrade() const {
    return this->signingGrade;
}

int AForm::getExecGrade() const {
    return this->execGrade;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (this->signingGrade < b.getGrade())
        throw GradeTooLowException();
    this->signedStatus = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (executor.getGrade() > this->execGrade)
        throw GradeTooLowException();
    if (!this->signedStatus)
        throw FormNotSignedException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Error: Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Error: Grade Too Low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Error: Form Is Not Signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << std::boolalpha
       << "Form Name: " << f.getName() << "\n"
       << "Signed: " << f.getSignedStatus() << "\n"
       << "Signing Grade: " << f.getSigningGrade() << "\n"
       << "Execution Grade: " << f.getExecGrade()
       << std::noboolalpha;
    return os;
}
