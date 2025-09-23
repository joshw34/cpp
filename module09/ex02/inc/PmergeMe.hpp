#pragma once

#include <vector>
#include <cstdlib>
#include <stdexcept> // IWYU pragma: keep
#include <iostream>
#include <list>
#include <iterator>

class PmergeMe {
 public:
  PmergeMe(const std::vector<int>&);
  ~PmergeMe();

  void sort();

 private:
  PmergeMe();
  PmergeMe(const PmergeMe&);
  PmergeMe& operator=(const PmergeMe&);

  std::vector<int> vec_data;
  std::list<int> lst_data;

  static const std::vector<int>& validateInput(const std::vector<int>&);
  static const std::list<int> initDataList(const std::vector<int>&);

  void printData(const std::string);

  template<typename Iterator>
  void mergeInsertSort(Iterator start, Iterator end, size_t pair_level) {
    (void)pair_level;
    for (Iterator it = start; it != end; ++it) {
      if (*it > *(std::next(it)))
        std::swap(*it, *std::next(it));
    }
  }
};
