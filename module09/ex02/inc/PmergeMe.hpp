#pragma once

#include <unistd.h>

#include <algorithm>  // IWYU pragma: keep
#include <cstdlib>
#include <ctime>
#include <iostream>  // IWYU pragma: keep
#include <list>
#include <stdexcept>  // IWYU pragma: keep
#include <vector>

class PmergeMe {
 public:
  PmergeMe(const std::vector<int>&);
  ~PmergeMe();

  void sort();

 private:
  PmergeMe();
  PmergeMe(const PmergeMe&);
  PmergeMe& operator=(const PmergeMe&);

  std::vector<int> input_data;
  std::vector<size_t> jacobsthal;
  static const int NO_PAIR = -1;
  static const int DONE = -10;

  static const std::vector<int>& validateInput(const std::vector<int>&);
  static const std::vector<size_t> initJacobsthal(const size_t);

  void vectorSort(std::vector<int>&);
  void vectorInsert(std::vector<int>&, std::vector<std::pair<int, int> >&);
  void listSort(std::list<int>&);
  void listInsert(std::list<int>&, std::list<std::pair<int, int> >&);
  std::list<std::pair<int, int> >::iterator getStartIterator(std::list<std::pair<int, int> >&, size_t);

  template <typename Container>
  void printContainer(Container data, const std::string prefix) {
    typename Container::const_iterator it = data.begin();
    std::cout << prefix << ": ";
    for (; it != data.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
  }

  template <typename Container>
  bool handleBaseCase(Container& data) {
    if (data.size() <= 2) {
      if (data.size() == 2 && (data.front() > data.back()))
        std::swap(data.front(), data.back());
      return true;
    }
    return false;
  }

  template <typename Container>
  bool checkResult(const Container& data) {
    int previous = -1;
    typename Container::const_iterator it = data.begin();
    for (; it != data.end(); ++it) {
      int current = *it;
      if (current < previous)
        return false;
      previous = current;
    }
    return true;
  }

  template <typename Container>
  void printStats(Container& data, double time, std::string type) {
    std::cout << std::fixed
              << "Time to process a range of " << data.size()
              << " elements with std::" << type << " : " << time << " ms" << "\n";
  }
};
