#include "../inc/Span.hpp"
#include "../inc/Colors.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <list>
#include <vector>
#include <iterator>

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

  std::vector<int> vec;
  vec.push_back(3);
  vec.push_back(7);
  vec.push_back(18);
  vec.push_back(30);
  vec.push_back(42);
  vec.push_back(56);
  vec.push_back(70);
  vec.push_back(89);
  vec.push_back(127);
  vec.push_back(130);
  vec.push_back(200);

  std::list<int> lst;
  lst.push_back(12);
  lst.push_back(22);
  lst.push_back(39);
  lst.push_back(43);
  lst.push_back(58);
  lst.push_back(96);
  lst.push_back(120);
  lst.push_back(154);
  lst.push_back(156);
  lst.push_back(280);

  int arr[10] = {101, 125, 130, 148, 159, 180, 205, 300, 500, 1000};

  // Invalid N value
  {
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

  // Overflow
  {
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

  // Add Range
  {
    std::cout << BOLD << "\nAdd Range Test (std::vector)\n" << RESET;
    Span test(10);
    test.addRange(vec.begin(), vec.end() - 1);
    test.printSpanData();
    std::cout << test;
  }

  // Add Range Overflow
  {
    std::cout << BOLD << "\nAdd Range Overflow Test\n" << RESET;
    try {
      Span test(10);
      test.addRange(vec.begin(), vec.end());
      test.printSpanData();
      std::cout << test;
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << std::endl;
    }
  }

  // Test 1
  {
    std::cout << BOLD << "\nTest 1 (std::list)\n" << RESET;
    Span test(10);
    test.addRange(lst.begin(), lst.end());
    test.printSpanData();
    std::cout << test;
  }

  // Test 2
  {
    std::cout << BOLD << "\nTest 2 (c array)\n" << RESET;
    Span test(10);
    test.addRange(arr[0], arr[9]);
    test.printSpanData();
    std::cout << test;
  }
}
