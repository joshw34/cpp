#include "../inc/Intern.hpp"

const std::string Intern::form_types[n_form_types] = {
    "shrubbery creation", "robotomy request", "presidential pardon"
};

Intern::Intern() {
    std::cout << "Intern Default Constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern& src) {
    static_cast<void>(src);
    std::cout << BOLD << "Intern Copy Constructor called (nothing to copy)" << RESET << std::endl;
}

Intern::~Intern() {
    std::cout << BOLD << "Intern Destructor called" << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& src) {
    //Nothing to copy
    static_cast<void>(src);
    return *this;
}

/* Uses two arrays like a map (form name = createForm function pointer)
   Exception to prevent NULL pointer dereference */
AForm* Intern::makeForm(const std::string& form_name, const std::string& target) {
    for (size_t i = 0; i < n_form_types; i++) {
        if (form_types[i].compare(form_name) == 0) {
            AForm* form = form_creator[i](target);
            std::cout << GREEN << "Intern created " << form->getName() << RESET << std::endl;
            return form;
        }
    }
    std::cout << RED << "Error: " << form_name << " not found" << RESET << std::endl;
    throw FormNotCreatedException();
}

const char* Intern::FormNotCreatedException::what() const throw() {
    return "Error: form was not created. NULL pointer returned";
}

//Array of const pointers to intern functions that return AForm* and take std::string parameter
AForm* (*const Intern::form_creator[n_form_types])(const std::string&) = {
    &createShrubbery, &createRobotomy, &createPardon,
};

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}
