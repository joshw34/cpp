#pragma once

#include <algorithm>  // IWYU pragma: keep
#include <iostream>
#include <numeric>    // IWYU pragma: keep
#include <stdexcept>  // IWYU pragma: keep
#include <vector>

#include "../inc/Colors.hpp"  // IWYU pragma: keep

class Span {
 public:
  Span();
  Span(const unsigned int N);
  Span(const int N);  // Needed to avoid implicit casting from negative -> uint
  Span(const Span& src);
  ~Span();

  Span& operator=(const Span& src);

  void addNumber(const int num);
  int shortestSpan();
  int longestSpan() const;

  template <typename Iterator>
  void addRange(Iterator start, Iterator end) {
    long range_size = std::distance(start, end);
    if (range_size > static_cast<long>(max - data.size()))
      throw std::out_of_range("Error: Range is too large");
    data.reserve(data.size() + range_size);
    data.insert(data.end(), start, end);
  }

  void printSpanData() const;

 private:
  unsigned int max;
  std::vector<int> data;
};

std::ostream& operator<<(std::ostream& os, Span& s);
