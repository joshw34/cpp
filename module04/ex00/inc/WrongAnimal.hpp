#pragma once

#include <iostream>  // IWYU pragma: keep

#include "Colors.hpp"  // IWYU pragma: keep

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& src);
  ~WrongAnimal();

  WrongAnimal& operator=(const WrongAnimal& src);

  void makeSound() const;

  const std::string& getType() const;

 protected:
  WrongAnimal(const std::string& newType);
  std::string type;
};
