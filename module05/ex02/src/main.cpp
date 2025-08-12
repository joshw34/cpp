#include "../inc/Bureaucrat.hpp"
#include "../inc/Colors.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main() {
  // Create bureaucrats with different grades
  Bureaucrat president("President", 1);     // Can do everything
  Bureaucrat manager("Manager", 25);        // Can do presidential and robotomy
  Bureaucrat supervisor("Supervisor", 72);  // Can do robotomy and shrubbery
  Bureaucrat intern("Intern", 150);         // Can only sign shrubbery

  std::cout << BLUE ITALIC << "\n=== Bureaucrats Created ===" << RESET
            << std::endl;
  std::cout << president << std::endl;
  std::cout << manager << std::endl;
  std::cout << supervisor << std::endl;
  std::cout << intern << "\n" << std::endl;

  // Create all three forms
  ShrubberyCreationForm shrub("garden");
  RobotomyRequestForm robot("Bender");
  PresidentialPardonForm pardon("Arthur Dent");

  std::cout << BLUE ITALIC << "\n=== Forms Created ===" << RESET << std::endl;
  std::cout << shrub << std::endl << std::endl;
  std::cout << robot << std::endl << std::endl;
  std::cout << pardon << std::endl << std::endl;

  // Test signing all forms with appropriate bureaucrats
  std::cout << BLUE ITALIC << "\n=== Form Signing Test ===" << RESET
            << std::endl;
  supervisor.signForm(shrub);  // Grade 72, needs 145 ✓
  supervisor.signForm(robot);  // Grade 72, needs 72 ✓
  manager.signForm(pardon);    // Grade 25, needs 25 ✓

  // Test signing failures
  std::cout << BLUE ITALIC << "\n=== Signing Failure Test ===" << RESET
            << std::endl;
  intern.signForm(robot);       // Grade 150, needs 72 ✗
  supervisor.signForm(pardon);  // Grade 72, needs 25 ✗

  // Test executing all forms
  std::cout << BLUE ITALIC << "\n=== Testing Form Execution ===" << RESET
            << std::endl;
  president.executeForm(shrub);  // Exec grade 137
  std::cout << "\n";
  president.executeForm(robot);  // Exec grade 45 (50% chance)
  std::cout << "\n";
  president.executeForm(robot);  // Try again for randomness
  std::cout << "\n";
  president.executeForm(robot);  // Try again for randomness
  std::cout << "\n";
  president.executeForm(robot);  // Try again for randomness
  std::cout << "\n";
  president.executeForm(pardon);  // Exec grade 5

  // Test execution failures
  std::cout << BLUE ITALIC << "\n=== Testing Execution Failures ===" << RESET
            << std::endl;
  intern.executeForm(shrub);       // Grade 150, needs 137 ✗
  supervisor.executeForm(pardon);  // Grade 72, needs 5 ✗

  // Test executing unsigned form
  std::cout << BLUE ITALIC
            << "\n=== Testing Unsigned Form Execution ===" << RESET
            << std::endl;
  PresidentialPardonForm unsignedPardon("John Doe");
  president.executeForm(unsignedPardon);  // Not signed ✗

  std::cout << GREEN << "\n=== All Tests Completed ===" << RESET << std::endl;

  return 0;
}
