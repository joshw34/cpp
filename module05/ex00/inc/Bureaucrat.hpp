#pragma once

#include "../inc/Colors.hpp" // IWYU pragma: keep
#include <iostream> // IWYU pragma: keep
#include <exception>
#include <string>

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, const int grade);
        Bureaucrat(const Bureaucrat& src);
        ~Bureaucrat();
    
        Bureaucrat& operator=(const Bureaucrat& src);        

        int getGrade() const;
        const std::string& getName() const;
        void incGrade();
        void decGrade();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is too high (max is 1)";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is too low (min is 150)";
                }
        };

    private:
        const std::string name;
        int grade;
        static const int MAX_GRADE = 1;
        static const int MIN_GRADE = 150;
};
