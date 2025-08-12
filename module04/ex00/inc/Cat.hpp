#pragma once

#include <iostream>  // IWYU pragma: keep

#include "Animal.hpp"
#include "Colors.hpp"  // IWYU pragma: keep

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat& src);
  ~Cat();

  Cat& operator=(const Cat& src);

  void makeSound() const;
};
