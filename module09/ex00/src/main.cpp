#include <iostream>

#include "../inc/BitcoinExchange.hpp"
#include "../inc/Colors.hpp"

int main(int ac, char** av) {
  if (ac != 2) {
    std::cerr << "Error: Incorrect number of arguments\nCorrect Usage:"
              << " ./btc" << ITALIC << " input_file\n" << RESET;
    return EXIT_FAILURE;
  }
  if (av[1][0] == '\0') {
    std::cerr << "Error: Filename can not be null\n";
    return EXIT_FAILURE;
  }

  try {
    BitcoinExchange btc(av[1]);
    btc.run();
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
