#include "../inc/Bureaucrat.hpp"

int main() {
    {
        try {
            Bureaucrat jim("Jim", 0);
        } catch (const std::exception& e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }

        try {
            Bureaucrat mark("Mark", 151);
        } catch (const std::exception& e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    std::cout << "\n******************************\n" << std::endl;
    {
        Bureaucrat dave("Dave", 1);
        Bureaucrat john("John", 150);

        try {
            dave.incGrade();
        } catch (const std::exception& e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }

        try {
            john.decGrade();
        } catch (const std::exception& e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}
