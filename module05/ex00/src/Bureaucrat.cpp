#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(MIN_GRADE) {
    std::cout << BOLD << "Default Bureaucrat Constructor Called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : name(name) {
    std::cout << BOLD << "Bureaucrat Constructor Called for " << name << RESET << std::endl;

    if (grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (grade > MIN_GRADE)
        throw GradeTooLowException();

    this->grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.getName()), grade(src.getGrade()) {
    std::cout << BOLD << "Bureaucrat Copy Constructor Called to copy " << name << RESET << std::endl;
};

Bureaucrat::~Bureaucrat() {
    std::cout << BOLD << "Bureaucrat Destructor Called for " << name << RESET << std::endl;
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
