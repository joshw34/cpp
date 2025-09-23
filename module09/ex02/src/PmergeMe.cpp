#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int>& input)
    : vec_data(validateInput(input)),
      lst_data(initDataList(input)),
      jacobsthal(initJacobsthal(input.size())) {}

PmergeMe::PmergeMe(const PmergeMe& src)
    : vec_data(src.vec_data), lst_data(src.lst_data), jacobsthal(src.jacobsthal) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
  if (this != &src) {
    this->vec_data = src.vec_data;
    this->lst_data = src.lst_data;
    this->jacobsthal = src.jacobsthal;
  }
  return *this;
}

void PmergeMe::sort() {
  std::vector<std::pair<int, int> > vec_pairs = getVecPairs();
  vectorSort(vec_pairs);
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

// result[n] = result[n-1] + (2 * result[n-2])
const std::vector<int> PmergeMe::initJacobsthal(const int input_size) {
  std::vector<int> result;
  result.push_back(0);
  result.push_back(1);
  while (result.back() < input_size) 
    result.push_back(result.back() + (2 * result[result.size() - 2]));
  return result;
}

std::vector<std::pair<int, int> > PmergeMe::getVecPairs() {

}

void PmergeMe::vectorSort(std::vector<std::pair<int, int> >& data) {
  if (data.size() <= 2) {
    if (data.size() == 2 && data.front().first < data.back().first)
      std::swap(data.front(), data.back());
    return;
  }
  std::vector<std::pair<int, int> > winners;
  std::vector<std::pair<int, int> > losers;
  winners.reserve(data.size() / 2 + 1);
  losers.reserve(data.size() / 2 + 1);
  for (std::vector<std::pair<int, int> >::iterator it = data.begin(); it != data.end();) {
    std::vector<std::pair<int, int> >::iterator next_it = it;
    ++next_it;
    if (next_it != data.end()) {
      if (it->first >= next_it->first) {
        winners.push_back(*it);
        losers.push_back(*next_it);
      }
      else {
        winners.push_back(*next_it);
        losers.push_back(*it);
      }
      it = next_it;
      ++it;
    }
    else {
      losers.push_back(*it);
      ++it;
    }
    vectorSort(winners);
  }
}
