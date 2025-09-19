#pragma once

#include <vector>
#include <cstdlib>
#include <stdexcept> // IWYU pragma: keep
#include <iostream>

class PmergeMe {
 public:
  PmergeMe(const std::vector<int>&);
  ~PmergeMe();

  void sort();

 private:
  PmergeMe();
  PmergeMe(const PmergeMe&);
  PmergeMe& operator=(const PmergeMe&);

  std::vector<int> data;

  static const std::vector<int>& validateInput(const std::vector<int>&);

  void printData(const std::string);
};
