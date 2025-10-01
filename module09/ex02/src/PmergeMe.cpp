#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int>& input)
    : input_data(validateInput(input)),
      jacobsthal(initJacobsthal(input.size())) {}

PmergeMe::PmergeMe(const PmergeMe& src)
    : input_data(src.input_data), jacobsthal(src.jacobsthal) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
  if (this != &src) {
    this->input_data = src.input_data;
    this->jacobsthal = src.jacobsthal;
  }
  return *this;
}

void PmergeMe::sort() {
  clock_t start, end;
  double vec_time, lst_time;

  start = clock();
  std::vector<int> vec_data(input_data.begin(), input_data.end());
  vectorSort(vec_data);
  end = clock();
  vec_time = static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC) * 1000;

  start = clock();
  std::list<int> lst_data(input_data.begin(), input_data.end());
  listSort(lst_data);
  end = clock();
  lst_time = static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC) * 1000;

  printContainer(input_data, "Before");

  if (!checkResult(vec_data))
    throw std::runtime_error("std::vector failed");
  if (!checkResult(lst_data))
    throw std::runtime_error("std::list failed");

  printContainer(lst_data, "After ");
  printStats(vec_data, vec_time, "vector");
  printStats(lst_data, lst_time, "list");
}

const std::vector<int>& PmergeMe::validateInput(const std::vector<int>& input) {
  for (size_t i = 0; i < input.size(); ++i) {
    if (input.at(i) < 1)
      throw std::invalid_argument("Non-positive Value in Input");
  }
  return input;
}

// result[n] = result[n-1] + (2 * result[n-2])
// result[n] = index number
const std::vector<size_t> PmergeMe::initJacobsthal(const size_t input_size) {
  std::vector<size_t> result;
  result.push_back(0);
  result.push_back(1);
  while (result.back() < input_size)
    result.push_back(result.back() + (2 * result[result.size() - 2]));
  result.erase(result.begin());
  result.erase(result.begin());
  for (size_t i = 0; i < result.size(); ++i) result[i] -= 1;
  return result;
}

void PmergeMe::vectorSort(std::vector<int>& data) {
  if (handleBaseCase(data))
    return;
  std::vector<int> winners;
  std::vector<std::pair<int, int> > pairs;
  winners.reserve(data.size() / 2 + 1);
  pairs.reserve(data.size() / 2 + 1);
  for (std::vector<int>::iterator it = data.begin(); it != data.end();) {
    std::vector<int>::iterator next_it = it;
    ++next_it;
    if (next_it != data.end()) {
      winners.push_back(std::max(*it, *next_it));
      pairs.push_back(std::make_pair(winners.back(), std::min(*it, *next_it)));
      it = next_it;
      ++it;
    } else {
      winners.push_back(*it);
      pairs.push_back(std::make_pair(winners.back(), NO_PAIR));
      ++it;
    }
  }
  vectorSort(winners);
  vectorInsert(winners, pairs);
  data.swap(winners);
}

void PmergeMe::vectorInsert(std::vector<int>& winners, std::vector<std::pair<int, int> >& pairs) {
  for (size_t i = 0; i < jacobsthal.size(); ++i) {
    size_t index = (jacobsthal[i] < pairs.size()) ? jacobsthal[i] : pairs.size() - 1;
    for (; pairs[index].first != DONE; --index) {
      int w_val = pairs[index].first;
      int l_val = pairs[index].second;
      if (l_val == NO_PAIR)
        continue;
      pairs[index].first = DONE;
      std::vector<int>::iterator w_pos = std::find(winners.begin(), winners.end(), w_val);
      std::vector<int>::iterator insert_pos = std::lower_bound(winners.begin(), w_pos, l_val);
      winners.insert(insert_pos, l_val);
      if (index == 0)
        break;
    }
  }
}

void PmergeMe::listSort(std::list<int>& data) {
  if (handleBaseCase(data))
    return;
  std::list<int> winners;
  std::list<std::pair<int, int> > pairs;
  for (std::list<int>::iterator it = data.begin(); it != data.end();) {
    std::list<int>::iterator next_it = it;
    ++next_it;
    if (next_it != data.end()) {
      winners.push_back(std::max(*it, *next_it));
      pairs.push_back(std::make_pair(winners.back(), std::min(*it, *next_it)));
      it = next_it;
      ++it;
    } else {
      winners.push_back(*it);
      pairs.push_back(std::make_pair(winners.back(), NO_PAIR));
      ++it;
    }
  }
  listSort(winners);
  listInsert(winners, pairs);
  data.swap(winners);
}

void PmergeMe::listInsert(std::list<int>& winners, std::list<std::pair<int, int> >& pairs) {
  for (size_t i = 0; i < jacobsthal.size(); ++i) {
    size_t index = (jacobsthal[i] < pairs.size()) ? jacobsthal[i] : pairs.size() - 1;
    std::list<std::pair<int, int> >::iterator it = getStartIterator(pairs, index);
    for (; it->first != DONE; --it) {
      int w_val = it->first;
      int l_val = it->second;
      if (l_val == NO_PAIR)
        continue;
      it->first = DONE;
      std::list<int>::iterator w_pos = std::find(winners.begin(), winners.end(), w_val);
      std::list<int>::iterator insert_pos = std::lower_bound(winners.begin(), w_pos, l_val);
      winners.insert(insert_pos, l_val);
      if (it == pairs.begin())
        break;
    }
  }
}

std::list<std::pair<int, int> >::iterator PmergeMe::getStartIterator(std::list<std::pair<int, int> >& data, size_t index) {
  std::list<std::pair<int, int> >::iterator it = data.begin();
  std::advance(it, index);
  return it;
}
