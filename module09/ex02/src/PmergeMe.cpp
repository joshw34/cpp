#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int>& input) : data(validateInput(input)) {}

PmergeMe::PmergeMe(const PmergeMe& src) : data(src.data) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
  if (this != &src) {
    this->data = src.data;
  }
  return *this;
}

void PmergeMe::sort() {
  printData("Before");
}

const std::vector<int>& PmergeMe::validateInput(const std::vector<int>& input) {
  for (size_t i = 0; i < input.size(); ++i) {
    if (input.at(i) < 1)
      throw std::invalid_argument("Negative Value in Input");
  }
  return input; 
}

void PmergeMe::printData(const std::string prefix) {
  std::cout << prefix << ": ";
  for (size_t i = 0; i < data.size(); ++i) {
    std::cout << data.at(i) << " ";
  } 
  std::cout << std::endl;
}
