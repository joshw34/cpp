#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default_target") {
    std::cout << BOLD << "PresidentialPardonForm Default Constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
    std::cout << BOLD << "PresidentialPardonForm Constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), target(src.getTarget()) {
    std::cout << BOLD << "PresidentialPardonForm Copy Constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << BOLD << "PresidentialPardonForm Destructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
    if (this != &src) {
        AForm::operator=(src);
        this->target = src.getTarget();
    }
    return *this;
}

const std::string& PresidentialPardonForm::getTarget() const {
    return this->target;
}

void PresidentialPardonForm::executeAction() const {
    std::cout << GREEN << target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}
