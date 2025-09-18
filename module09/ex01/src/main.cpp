#include "../inc/RPN.hpp"
#include "../inc/Colors.hpp"

int main(int ac, char** av) {
  if (ac != 2 || (ac == 2 && av[1][0] == '\0')) {
    std::cerr << "Error: Correct Usage: ./RPN" << ITALIC << " expression\n";
    return EXIT_FAILURE;
  }

  try {
    RPN test(av[1]);
    test.solve();
  } catch (const std::invalid_argument& e) {
    std::cerr << RED << "Error: " << e.what() << "\n";
  }

  /*(void)ac;
  (void)av;
  std::string expressions[30] = {
    "3 5 +",
    "8 2 *",
    "4 6 + 2 -",
    "9 3 5 * /",
    "1 7 * 2 8 + +",
    "6 4 - 9 3 / *",
    "2 3 + 4 5 * +",
    "8 7 1 9 4 + - * /",
    "3 2 * 4 1 + 5 + +",
    "9 6 - 8 4 / 2 3 * + +",
    "1 2 + 3 4 + * 5 6 + +",
    "8 9 7 5 3 2 4 - + * / - +",
    "2 3 4 + * 5 6 7 + * + 8 +",
    "1 8 * 6 4 / + 2 7 - 5 3 / * -",
    "1 2 3 + 4 + * 5 6 7 + 8 + * + 9 +",
    "9 8 - 7 6 * + 5 4 / 3 2 - 1 + * -",
    "1 2 + 3 * 4 5 6 + + * 7 8 9 + + *",
    "9 8 7 * - 6 5 / + 4 3 - 2 1 + * /",
    "1 2 + 3 4 + * 5 6 + 7 8 + 9 + * + 1 +",
    "9 8 - 7 * 6 5 / 4 + * 3 2 - 1 8 + / *",
    "1 2 + 3 4 + * 5 6 + 7 8 + * + 9 -",
    "8 4 2 + / 9 3 - 6 * 7 5 + - 1 * +",
    "2 3 4 * + 5 6 7 + * + 8 9 1 + + /",
    "9 1 + 2 * 3 + 4 5 - 6 * 7 + 8 9 * - +",
    "3 4 + 5 * 6 7 + 8 * 9 + - 1 2 + /",
    "6 2 3 + / 4 * 5 7 8 - + * 9 1 - +",
    "1 9 2 + * 8 + 3 7 4 + * 6 * + 5 -",
    "4 5 6 + * 2 / 7 8 9 + + 1 * + 3 4 + -",
    "2 8 + 3 * 7 + 4 6 + 5 * 9 + - 1 7 + +",
    "9 8 7 * + 6 5 - / 4 3 2 + * + 1 8 - *"
  };

  for (int i = 0; i < 30; ++i) {
    std::cout << BLUE << "Test " << i + 1 << ": " << RESET
              << '"' << expressions[i] << '"' << "\n";
    try {
        RPN test(expressions[i]);
        test.solve();
        std::string dc = "echo \"6 k " + expressions[i] + " p\" | dc";
        (void)system(dc.c_str());
    } catch (const std::exception& e) {
        std::cerr << RED << "Error: " << expressions[i] << "\n" << e.what();
        break;
    }
    std::cout << "\n";
  }*/

  return EXIT_SUCCESS;
}
