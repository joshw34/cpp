#include "../inc/Span.hpp"
#include "../inc/Colors.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <iomanip>

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
  }
  {
    std::cout << BOLD << "Large Data Set (10,000,000 numbers)\n" << RESET;
    Span test(10000000);
    
    for (int i = 10000000; i > 0; --i) {
      test.addNumber(i);
    }

    std::cout << "short: " << test.shortestSpan() << "\n"
              << "long:  " << test.longestSpan() << "\n"
              << std::endl;
  }*/
  time_t start, end;
  srand(std::time(0));
  std::vector<int> test;
  for (int i = 0; i < 10000000; ++i) {
    test.push_back(rand());
  }

  {
    time(&start);

    int shortest = INT_MAX;
    int diff;

    for (size_t i = 0; i < test.size(); ++i) {
      for (size_t j = i + 1; j < test.size(); ++j) {
        diff = std::max(test[i], test[j]) - std::min(test[i], test[j]);
        shortest = (diff < shortest) ? diff : shortest;
      }
    }

    std::cout << std::fixed
              << "short: " << shortest << "\n"
              << "long:  " << *std::max_element(test.begin(), test.end()) - *std::min_element(test.begin(), test.end()) << "\n";
    
    time(&end);
    std::cout << "Time taken: " << end - start << "\n";
  }

  {
    time(&start);

    std::vector<int> compare(test.size());
    
    std::sort(test.begin(), test.end());
    std::adjacent_difference(test.begin(), test.end(), compare.begin());
    
    std::cout << std::fixed
              << "short: " << *std::min_element(compare.begin() + 1, compare.end()) << "\n"
              << "long:  " << *std::max_element(test.begin(), test.end()) - *std::min_element(test.begin(), test.end()) << "\n";
    
    time(&end);
    std::cout << "Time taken: " << end - start << "\n";
  }
}
