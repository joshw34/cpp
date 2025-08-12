#pragma once

#include <iostream>  // IWYU pragma: keep
#include <string>

#include "Colors.hpp"  // IWYU pragma: keep

class Brain {
 public:
  Brain();
  Brain(const Brain& src);
  ~Brain();

  Brain& operator=(const Brain& src);

  const std::string& getIdea(int index) const;
  void printIdea(int index, const std::string& type) const;
  void setIdea(int index, const std::string& newIdea);

 private:
  static const int brainSize = 100;
  std::string ideas[brainSize];
};
