#include <cstdlib>
#include <iostream>
#include <string>

#include "Colors.hpp"

template <typename T>
T Sum(T input) {
  return input;
}

template <typename T1, typename T2>
auto multiply(T1 input1, T2 input2) {
  return input1 * input2;
}

template <typename T>
T add(T input1, T input2) {
  return input1 + input2;
}

template <typename T>
void testPrint(T input, size_t n) {
  for (size_t i = 0; i < n; i++) {
    std::cout << input << "\n";
  }
  std::cout << std::endl;
}

template <typename T, size_t N>
void printStrN(T input) {
  for (size_t i = 0; i < N; i++) {
    std::cout << input << "\n";
  }
  std::cout << std::endl;
}

template <typename T>
T square(T input) {
  return input * input;
}

int main() {
  // Compiler will create a version for each of the following types
  // (template argument deduction):
  std::cout << BOLD ITALIC << "Template Argument Deduction:\n" << RESET
            << square(5) << "\n"
            << square(5.5) << "\n"
            << square(6.5f) << "\n"
            << "\n";

  // Can also explicitly call the compiler-created versions:
  std::cout << BOLD ITALIC << "Specified types:\n" << RESET
            << square<int>(5) << "\n"
            << square<double>(5.5) << "\n"
            << square<float>(6.5f) << "\n\n";

  // Can use non-object parameters:
  // (This will produce different version of function for every N value)
  std::cout << BOLD ITALIC << "Using Non-Object Parameters:" << RESET << "\n";
  printStrN<std::string, 5>("Hello, World!");

  // Only one version of the function created per T type
  testPrint(std::string("Hello, World!"), 5);

  // Multiple parameters:
  std::cout << BOLD ITALIC << "Multiple Parameters:" << RESET << "\n"
            << add(10, 32) << "\n"
            << add(10.5f, 31.5f) << "\n\n";

  // Multiple parameter types
  std::cout << BOLD ITALIC << "Multiple Parameter Types:" << RESET << "\n"
            << multiply(4, 10.5) << "\n\n";

  // Variadic:
  std::cout << BOLD ITALIC << "Variadic:" << RESET << "\n";
  std::cout << Sum(1) << std::endl;
  return 0;
}
