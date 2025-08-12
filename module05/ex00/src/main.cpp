#include "../inc/Bureaucrat.hpp"

int main() {
  {
    std::cout << "Constructor Tests: \n" << std::endl;

    Bureaucrat a("A", 15);
    Bureaucrat b(a);
    Bureaucrat c("C", 98);

    c = b;  // will assign b grade to c. name is const so can't be assigned
    std::cout << "\n" << a << "\n" << b << "\n" << c << "\n" << std::endl;
  }
  std::cout << "\n******************************\n" << std::endl;
  {
    std::cout << "Constructor Exception Tests:\n" << std::endl;

    try {
      Bureaucrat jim("Jim", 0);
      std::cout << GREEN << jim << RESET << std::endl;
    } catch (const std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;

    try {
      Bureaucrat mark("Mark", 151);
      std::cout << GREEN << mark << RESET << std::endl;
    } catch (const std::exception& e) {
      std::cout << RED << e.what() << RESET << std::endl;
    }
  }
  std::cout << "\n******************************\n" << std::endl;
  {
    std::cout << "Increment/Decrement Exception Tests\n" << std::endl;

    Bureaucrat dave("Dave", 5);
    std::cout << dave << "\n" << std::endl;
    Bureaucrat john("John", 146);
    std::cout << john << "\n" << std::endl;

    for (int i = dave.getGrade(); i > 0; i--) {
      try {
        dave.incGrade();
        std::cout << GREEN << "Increment successful: " << dave << RESET
                  << std::endl;
      } catch (const std::exception& e) {
        std::cout << RED << e.what() << "\n"
                  << "Increment Failed: " << dave << RESET << std::endl;
      }
    }
    std::cout << std::endl;
    for (int i = john.getGrade(); i <= 150; i++) {
      try {
        john.decGrade();
        std::cout << GREEN << "Decrement successful: " << john << RESET
                  << std::endl;
      } catch (const std::exception& e) {
        std::cout << RED << e.what() << "\n"
                  << "Decrement Failed: " << john << RESET << std::endl;
      }
    }
    std::cout << std::endl;
  }
}
