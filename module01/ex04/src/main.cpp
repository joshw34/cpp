#include <cstdlib>

#include "../inc/StrReplace.hpp"

int main(int ac, char** av) {
  StrReplace replacer;

  if (ac != 4) {
    std::cerr << "Error: Incorrect number of arguments provided" << std::endl;
    return EXIT_FAILURE;
  }
  if (!replacer.setInfile(av[1]))
    return EXIT_FAILURE;
  if (!replacer.setStrings(av[2], av[3]))
    return EXIT_FAILURE;
  if (!replacer.replace())
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
