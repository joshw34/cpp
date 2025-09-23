#pragma once

#include <vector>
#include <cstdlib>
#include <stdexcept> // IWYU pragma: keep
#include <iostream> // IWYU pragma: keep
#include <list>
#include <iterator>
#include <algorithm>

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
  std::vector<int> jacobsthal;

  static const std::vector<int>& validateInput(const std::vector<int>&);
  static const std::list<int> initDataList(const std::vector<int>&);
  static const std::vector<int> initJacobsthal(const int); 

  std::vector<std::pair<int, int> > getVecPairs() const;
  void vectorSort(std::vector<std::pair<int, int> >&);
  void vectorInsert(std::vector<std::pair<int, int> >&, std::vector<std::pair<int, int> >&);

  template<typename Iterator>
  void printContainer(Iterator start, Iterator end, const std::string prefix) {
    std::cout << prefix << ": ";
    for (Iterator it = start; it != end; ++it)
      std::cout << *it << " ";
    std::cout << std::endl;
  }
};
