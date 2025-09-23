#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int>& input)
    : vec_data(validateInput(input)), lst_data(initDataList(input)) {}

PmergeMe::PmergeMe(const PmergeMe& src)
    : vec_data(src.vec_data), lst_data(src.lst_data) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
  if (this != &src) {
    this->vec_data = src.vec_data;
    this->lst_data = src.lst_data;
  }
  return *this;
}

void PmergeMe::sort() {
  printData("Before");
  for (std::list<int>::iterator it = lst_data.begin(); it != lst_data.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
  mergeInsertSort(vec_data.begin(), vec_data.end(), 0);
  mergeInsertSort(lst_data.begin(), lst_data.end(), 0);
  printData("After");
  for (std::list<int>::iterator it = lst_data.begin(); it != lst_data.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

const std::vector<int>& PmergeMe::validateInput(const std::vector<int>& input) {
  for (size_t i = 0; i < input.size(); ++i) {
    if (input.at(i) < 1)
      throw std::invalid_argument("Non-positive Value in Input");
  }
  return input;
}

const std::list<int> PmergeMe::initDataList(const std::vector<int>& input) {
  std::list<int> result;
  result.insert(result.begin(), input.begin(), input.end());
  return result;
}

void PmergeMe::printData(const std::string prefix) {
  std::cout << prefix << ": ";
  for (size_t i = 0; i < vec_data.size(); ++i) {
    std::cout << vec_data.at(i) << " ";
  }
  std::cout << std::endl;
}
