#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

int main() {
    Bureaucrat jeff("Jeff", 10);
    std::cout << jeff << "\n" << std::endl;

    Form b265("B265", 11, 11);
    std::cout << b265 << "\n" << std::endl;

    Form f683("F683", 9, 9);
    std::cout << f683 << "\n" << std::endl;

    jeff.signForm(b265);
    jeff.signForm(f683);

    std::cout << std::endl;
}
