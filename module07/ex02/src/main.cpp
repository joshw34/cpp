#include <iostream>

#include "../inc/Array.hpp"
#include "../inc/Colors.hpp"

int main() {
  {
    // EMPTY ARRAY / ASSIGNMENT OPERATOR TEST
    Array<int> empty;
    Array<int> full(5);

    full[0] = 0;
    full[1] = 10;
    full[2] = 20;
    full[3] = 30;
    full[4] = 40;

    std::cout << BOLD GREEN << "Empty Array & Assignement Operator Test\n" << RESET
              << BLUE << "Empty Array:\n" << RESET << empty << "\n"
              << BLUE << "Full Array:\n" << RESET << full << "\n";

    empty = full;

    std::cout << BLUE << "Empty Array:\n" << RESET << empty << "\n"
              << BLUE << "Full Array:\n" << RESET << full << "\n";

  }
  {
    // COPY CONSTRUCTOR / DEEP COPY TEST
    Array<std::string> original(5);

    original[0] = "this";
    original[1] = "is";
    original[2] = "a";
    original[3] = "test";
    original[4] = "array";

    Array<std::string> copy(original);

    std::cout << BOLD GREEN << "Copy Constructor & Deep Copy Test\n" << RESET
              << BLUE << "Original Array:\n" << RESET << original << "\n"
              << BLUE << "Copy Constructed Array:\n" << RESET << copy << "\n";

    original[0] = "empty";
    original[1] = "empty";
    original[2] = "empty";
    original[3] = "empty";
    original[4] = "empty";

    std::cout << BLUE << "Original Array (Modified):\n" << RESET <<original << "\n"
              << BLUE << "Copy Constructed Array:\n" << RESET << copy << "\n";
  }
  {
    // OUT OF BOUNDS ACCESS TEST
    Array<float> arr(5);

    arr[0] = 0.5f;
    arr[1] = 1.3f;
    arr[2] = 2.8f;
    arr[3] = 3.2f;
    arr[4] = 4.1f;

    std::cout << GREEN BOLD << "Out of Bounds Access Test\n" << RESET;

    for (int i = -1; i < 6; ++i) {
      try {
         std::cout << arr[i] << "\n";
      } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << "\n";
      }
    }
  }
}
