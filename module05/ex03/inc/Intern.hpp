#pragma once

#include "Colors.hpp" // IWYU pragma: keep
#include "AForm.hpp"
#include <iostream> // IWYU pragma: keep
#include <string>
#include <exception>
#include "ShrubberyCreationForm.hpp" // IWYU pragma: keep
#include "RobotomyRequestForm.hpp" // IWYU pragma: keep
#include "PresidentialPardonForm.hpp" // IWYU pragma: keep

class Intern {
    public:
        Intern();
        Intern(const Intern& src);
        ~Intern();

        Intern& operator=(const Intern& src);

        AForm* makeForm(const std::string& form_name, const std::string& target);

        class FormNotCreatedException : public std::exception {
            public:
                const char* what() const throw();
        };

    private:
        static const size_t n_form_types = 3;
        static const std::string form_types[n_form_types];
        static AForm* (*const form_creator[n_form_types])(const std::string&); //Function pointer array

        static AForm* createShrubbery(const std::string& target);
        static AForm* createRobotomy(const std::string& target);
        static AForm* createPardon(const std::string& target);
};
