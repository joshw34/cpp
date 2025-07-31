#pragma once

#include "Colors.hpp" // IWYU pragma: keep
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream> // IWYU pragma: keep
#include <string>

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        ~PresidentialPardonForm();

        PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

        const std::string& getTarget() const;

        void executeAction() const;

    private:
        std::string target;
};
