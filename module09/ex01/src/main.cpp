#include "../inc/RPN.hpp"
#include "../inc/Colors.hpp"

int main(int ac, char** av) {
  if (ac != 2 || (ac == 2 && av[1][0] == '\0')) {
    std::cerr << "Error: Correct Usage: ./RPN" << ITALIC << " expression\n";
    return EXIT_FAILURE;
  }
  try {
    RPN test(av[1]);
    test.run();
  } catch (const std::invalid_argument& e) {
    std::cerr << RED << "Error: " << e.what() << "\n";
  }
  return EXIT_SUCCESS;
}
