#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

int main() {
    Bureaucrat staff[3] = { Bureaucrat("Intern", 100), Bureaucrat("Manager", 50), Bureaucrat("CEO", 1) };
    Form forms[3] = { Form("LVL101", 101, 101), Form("LVL51", 51, 51), Form("LVL1", 1, 1) };

    // Print the 3 staff member details using << overload
    std::cout << BLUE ITALIC << "\nSTAFF: \n" << RESET;
    for(size_t i = 0; i < 3; i++) {
        std::cout << staff[i] << "\n";
    }
    std::cout << "\n";

    // For each form, print using << overload, try to sign. Cycle employees low->high until signed
    for(size_t i = 0; i < 3; i++) {
        std::cout << BLUE ITALIC << "TEST " << i + 1 << ":\n" << RESET
                  << forms[i] << "\n\n";

        for (size_t j = 0; j < 3 && !forms[i].getSignedStatus(); j++) {
            staff[j].signForm(forms[i]);
        }

        std::cout << "\n";
    }
}
