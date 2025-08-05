#include "../inc/ScalarConverter.hpp"
#include <cstdlib>
#include <stdexcept>

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << RED << "Error: One argument must be provided" << RESET << std::endl;
        return EXIT_FAILURE;
    }
    try {
        ScalarConverter::convert(av[1]);
    } catch (std::logic_error& e) {
        std::cerr << RED << "Error: Argument must not be NULL" << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    return EXIT_SUCCESS;
}
