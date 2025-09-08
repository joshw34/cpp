#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "../inc/Colors.hpp"
#include "../inc/easyfind.hpp"

int main() {
  std::vector<int> vec;
  std::list<int> lst;
  std::deque<int> deq;
  for (int i = 0; i < 100; ++i) {
    vec.push_back(i + 1);
    lst.push_back(i + i);
    deq.push_back(i + 1);
  }
  {
    // BASIC TEST
    std::cout << BOLD << "Basic Test\n" << RESET
              << "Vector:\t" << easyfind(vec, 42) << "\n"
              << "List:\t" << easyfind(lst, 42) << "\n"
              << "Deque:\t" << easyfind(deq, 42) << "\n\n";
  }
  {
    // INVALID VALUE 
    std::cout << BOLD << "Invalid Value\n" << RESET;
    
    try {
      std::cout << "Vector:\t" << easyfind(vec, 1000) << "\n";
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << "\n";
    }

    try {
      std::cout << "List:\t" << easyfind(lst, 1000) << "\n";
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << "\n";
    }
              
    try {
      std::cout << "Deque:\t" << easyfind(deq, 1000) << "\n";
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << "\n\n";
    }
  }
  {
    // EMPTY CONTAINER
    std::cout << BOLD << "Empty Container\n" << RESET;

    vec.clear();
    lst.clear();
    deq.clear();

    try {
      std::cout << "Vector:\t" << easyfind(vec, 42) << "\n";
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << "\n";
    }

    try {
      std::cout << "List:\t" << easyfind(lst, 42) << "\n";
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << "\n";
    }
              
    try {
      std::cout << "Deque:\t" << easyfind(deq, 42) << "\n";
    } catch (std::exception& e) {
      std::cerr << RED << e.what() << RESET << "\n";
    }
  }
}
