#pragma once

#include "../inc/Colors.hpp" // IWYU pragma: keep
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <fstream>
#include <iostream> // IWYU pragma: keep

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

        const std::string& getTarget() const;

        void executeAction() const;

        class FileOpenException : public std::exception {
            public:
                const char* what() const throw();
        };

    private:
        std::string target;
        void printTrees(std::ofstream& output_file) const;
};
