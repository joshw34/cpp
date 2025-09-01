#include "../inc/Span.hpp"
#include "../inc/Colors.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <list>
#include <map>

int main() {
  {
    std::cout << BOLD << "Test From Subject PDF\n" << RESET;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }

  {
    // Invalid N value
    std::cout << BOLD << "\nInvalid N Value Test\n" << RESET;
    try {
      Span invalid(-1);
      invalid.addNumber(42);
      invalid.addNumber(9);
      std::cout << invalid; 
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << std::endl;
    }
  }

  {
    // Overflow
    std::cout << BOLD << "\nOverflow Test\n" << RESET;
    try {
      Span overflow(10);
      for (int i = 0; i < 10; ++i)
        overflow.addNumber(i + 1);
      std::cout << overflow;
      overflow.addNumber(11);
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << std::endl;
    }
  }

  {
    // Add Range
    std::cout << BOLD << "\nAdd Range Test\n" << RESET;
    Span test(10);
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(18);
    nums.push_back(30);
    nums.push_back(42);
    nums.push_back(56);
    nums.push_back(70);
    nums.push_back(89);
    nums.push_back(127);
    nums.push_back(130);

    test.addRange(nums.begin(), nums.end());

    test.printSpanData();
    std::cout << test << std::endl;
  }

  {
    // Add Range Overflow
    std::cout << BOLD << "\nAdd Range Overflow Test\n" << RESET;
    try {
      Span test(10);
      std::vector<int> nums;
      nums.push_back(3);
      nums.push_back(7);
      nums.push_back(18);
      nums.push_back(30);
      nums.push_back(42);
      nums.push_back(56);
      nums.push_back(70);
      nums.push_back(89);
      nums.push_back(127);
      nums.push_back(130);
      nums.push_back(200);

      test.addRange(nums.begin(), nums.end());

      test.printSpanData();
      std::cout << test << std::endl;
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << std::endl;
    }
  }
}
