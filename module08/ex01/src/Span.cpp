#include "../inc/Span.hpp"

Span::Span() : max(0) {}

Span::Span(const unsigned int N) : max(N) {}

Span::Span(const int N) : max(N) { 
  if (N < 0)
    throw std::out_of_range("Error: Number of elements can not be negative");
}

Span::Span(const Span& src) : max(src.max), data(src.data) {}

Span::~Span() {}

Span& Span::operator=(const Span& src) {
  if (this != &src) {
    this->max = src.max;
    this->data = src.data;
  }
  return *this;
}

void Span::addNumber(const int num) {
  if (data.size() == max)
    throw std::out_of_range("Error: Cannot add more data");    
  data.push_back(num);
}

int Span::shortestSpan() {
  if (data.size() < 2)
    throw std::runtime_error("Error: Must have 2 or more elements");
  std::sort(data.begin(), data.end());
  std::vector<int> temp(data.size());
  std::adjacent_difference(data.begin(), data.end(), temp.begin());
  return *std::min_element(temp.begin() + 1, temp.end());
}

int Span::longestSpan() const {
  if (data.size() < 2)
    throw std::runtime_error("Error: Must have 2 or more elements");
  return *std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end());
}

void Span::printSpanData() const {
  if (data.size() == 0)
    std::cerr << RED << "Nothing to print" << RESET << std::endl;
  std::cout << "Span Data: [";
  for (size_t i = 0; i < data.size(); ++i) {
    std::cout << data.at(i) << ((i + 1 == data.size()) ? "" : ", ");
  }
  std::cout << "]\n";
}

std::ostream& operator<<(std::ostream& os, Span& s) {
  os << "Short: " << s.shortestSpan() << "\n"
     << "Long:  " << s.longestSpan() << "\n";
  return os;
}
