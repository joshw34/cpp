#pragma once

#include <cstdlib>
#include <iostream>

#include "Colors.hpp"

template <typename T>
void printData(const T& data) {
  std::cout << BOLD << "Value = " << RESET ITALIC << data << RESET
            << BOLD << "\tAddress = " << RESET ITALIC << &data << RESET
            << std::endl;
}

template <typename T>
void increment(T& num) {
  num++;
}

template <typename T, typename F>
void iter(T* arr, size_t len, F func) {
  for (size_t i = 0; i < len; ++i) func(arr[i]);
}
