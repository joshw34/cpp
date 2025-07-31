#include "../inc/Colors.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp" // IWYU pragma: keep
#include "../inc/RobotomyRequestForm.hpp" // IWYU pragma: keep
#include "../inc/PresidentialPardonForm.hpp" // IWYU pragma: keep
#include "../inc/Intern.hpp"

int main() {
    std::cout << BOLD BLUE ITALIC << "\n=== Testing Intern Class ===" << RESET << "\n";
    
    Intern someRandomIntern;
    std::cout << std::endl;
    
    // Create all valid forms, print name and delete
    std::cout << BOLD BLUE ITALIC << "=== Test 1: Creating Valid Forms ===" << RESET << "\n";
    try {
        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
        std::cout << "\n";
        AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << "\n";
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        
        std::cout << BLUE ITALIC << "\nSuccessfully created all forms:" << RESET << "\n";
        std::cout << *shrub << "\n\n";
        std::cout << *robot << "\n\n";
        std::cout << *pardon << "\n\n";
        
        std::cout << BLUE ITALIC << "\nDelete all forms:\n" << RESET;
        delete shrub;
        delete robot;
        delete pardon;
    } catch (const Intern::FormNotCreatedException& e) {
        std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }
    
    // Try to create invalid forms (should print error messge and throw exception)
    std::cout << BOLD BLUE ITALIC << "\n=== Test 2: Testing Invalid Form Names ===\n" << RESET;
    
    std::string invalidForms[] = {
        "invalid form",
        "shrubbery request",  // Wrong name
        "robot request",      // Wrong name
        "pardon form",        // Wrong name
        ""                    // Empty string
    };
    
    for (int i = 0; i < 5; i++) {
        try {
            std::cout << "Trying to create: \"" << invalidForms[i] << "\"" << std::endl;
            AForm* form = someRandomIntern.makeForm(invalidForms[i], "target");
            // Lines below should not execute
            std::cout << RED << "ERROR: Should have thrown exception!" << RESET << std::endl;
            delete form;
        } catch (const Intern::FormNotCreatedException& e) {
            std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
        }
        std::cout << "\n";
    }
    
    // Create form and test with bureaucrat 
    std::cout << BOLD BLUE ITALIC << "=== Test 3: Integration with Bureaucrats ===" << RESET << std::endl;
    try {
        Bureaucrat president("President", 1);
        std::cout << "\n";
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << "\n";
        
        std::cout << president << std::endl;
        std::cout << "\n";
        std::cout << *rrf << std::endl;
        std::cout << "\n";
        
        president.signForm(*rrf);
        std::cout << "\n";
        president.executeForm(*rrf);
        std::cout << "\n";
        
        delete rrf;
        
    } catch (const std::exception& e) {
        std::cout << RED << "Exception in integration test: " << e.what() << RESET << std::endl;
    }
    
    std::cout << BLUE ITALIC << "\n=== All Tests Complete ===" << RESET << std::endl;
    return 0;
}
