#pragma once

#include <iostream>  // IWYU pragma: keep

#include "Colors.hpp"  // IWYU pragma: keep
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat& src);
  ~WrongCat();

  WrongCat& operator=(const WrongCat& src);

  void makeSound() const;
};
