#include "../inc/Span.hpp"
#include "../inc/Colors.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <list>
#include <vector>
#include <ctime>
#include <fstream>
#include <deque>

template <typename T>
void fill_container(T& container, std::string file) {
  std::string line;
  std::ifstream input(file.c_str());
  container.clear();
  while (std::getline(input, line, '\n')) {
    container.push_back(std::atoi(line.c_str()));
  } 
  input.close();
}

int main() {
  /*{
    std::cout << BOLD << "Test From Subject PDF\n" << RESET;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }*/

  std::list<int> lst;
  std::vector<int> vec;
  std::deque<int> deq;

  // Test 1
  {
    std::cout << BOLD << "\nTest 1\n" << RESET;
    Span test(5);
    fill_container(lst, "./nums/5.txt");
    test.addRange(lst.begin(), lst.end());
    std::cout << test;
    test.printSpanData();
  }

  // Test 2
  {
    std::cout << BOLD << "\nTest 2\n" << RESET;
    Span test(5);
    fill_container(vec, "./nums/5-2.txt");
    test.addRange(vec.begin(), vec.end());
    std::cout << test;
    test.printSpanData();
  }

  // Test 3
  {
    std::cout << BOLD << "\nTest 3\n" << RESET;
    Span test(5);
    fill_container(deq, "./nums/5-3.txt");
    test.addRange(deq.begin(), deq.end());
    std::cout << test;
    test.printSpanData();
  }

  // Test 4
  {
    std::cout << BOLD << "\nTest 4\n" << RESET;
    Span test(10);
    fill_container(lst, "./nums/10.txt");
    test.addRange(lst.begin(), lst.end());
    std::cout << test;
    test.printSpanData();
  }

  // Test 5 
  {
    std::cout << BOLD << "\nTest 5\n" << RESET;
    Span test(10);
    fill_container(vec, "./nums/10-2.txt");
    test.addRange(vec.begin(), vec.end());
    std::cout << test;
    test.printSpanData();
  }

  // Test 6 
  {
    std::cout << BOLD << "\nTest 6\n" << RESET;
    Span test(10);
    fill_container(deq, "./nums/10-3.txt");
    test.addRange(deq.begin(), deq.end());
    std::cout << test;
    test.printSpanData();
  }

  // Test 7
  {
    std::cout << BOLD << "\nTest 7\n" << RESET;
    Span test(20);
    fill_container(lst, "./nums/20.txt");
    test.addRange(lst.begin(), lst.end());
    std::cout << test;
    test.printSpanData();
  }

  // Test 8
  {
    std::cout << BOLD << "\nTest 8\n" << RESET;
    Span test(20);
    fill_container(vec, "./nums/20-2.txt");
    test.addRange(vec.begin(), vec.end());
    std::cout << test;
    test.printSpanData();
  }

  // Test 9
  {
    std::cout << BOLD << "\nTest 9\n" << RESET;
    Span test(20);
    fill_container(deq, "./nums/20-3.txt");
    test.addRange(deq.begin(), deq.end());
    std::cout << test;
    test.printSpanData();
  }

  // Test 10
  {
    std::cout << BOLD << "\nTest 10\n" << RESET;
    Span test(1000000);
    fill_container(vec, "./nums/1000000.txt");
    test.addRange(vec.begin(), vec.end());
    std::cout << test;
  }

  // Invalid N value
 /* {
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

  // Range Overflow
  {
    std::cout << BOLD << "\nRange Overflow Test\n" << RESET;
    try {
      Span test(10);
      test.addRange(vec.begin(), vec.end());
      test.printSpanData();
      std::cout << test;
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << std::endl;
    }
  }*/
}
