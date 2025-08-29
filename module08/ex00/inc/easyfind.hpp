#pragma once

#include <algorithm>
#include <stdexcept>

template<typename T>
int easyfind(T data, const int to_find) {
  typename T::iterator it = std::find(data.begin(), data.end(), to_find);
  if (it == data.end())
    throw std::out_of_range("Error: Value Not Found"); 
  return *it;
}
