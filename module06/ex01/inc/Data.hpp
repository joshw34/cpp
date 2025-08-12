#pragma once

#include <ostream>
#include <string>

#include "../inc/Colors.hpp"  // IWYU pragma: keep

struct Data {
  Data();
  Data(const std::string& name, const int age);
  Data(const Data& src);
  ~Data();
  Data& operator=(const Data& src);

  std::string name;
  int age;
};

std::ostream& operator<<(std::ostream& os, const Data& data);
