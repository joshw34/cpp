#include <sstream>
#include <stdexcept>

#include "../inc/ScalarConverter.hpp"

int main(int ac, char** av) {
  if (ac != 2) {
    std::cerr << RED << "Error: One argument must be provided" << RESET << std::endl;
    return EXIT_FAILURE;
  }
  try {
    ScalarConverter::convert(av[1]);
  } catch (std::logic_error& e) {
    std::cerr << RED << "Error: Argument must not be NULL" << RESET << std::endl;
    return EXIT_FAILURE;
  } catch (std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  }
  /*(void)ac; (void)av;
  std::ostringstream str;
  for (int i = -1; i < 130; i++) {
      std::cout << "Test " << i << "\n--------------------\n";
      str << i;
      ScalarConverter::convert(str.str());
      std::cout << "\n";
      str.str("");
  }*/
  return EXIT_SUCCESS;
}
