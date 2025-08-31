#pragma once

#include <vector>
#include <cstdlib>
#include <stdexcept> // IWYU pragma: keep
#include <algorithm> // IWYU pragma: keep
#include <numeric> // IWYU pragma: keep

class Span {
  public:
    Span();
    Span(const unsigned int N);
    Span(const Span& src);
    ~Span();

    Span& operator=(const Span& src);

    void addNumber(const int num);
    int shortestSpan();
    int longestSpan() const;

  private:
    unsigned int max;
    std::vector<int> data;
};
