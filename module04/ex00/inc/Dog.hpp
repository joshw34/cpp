#pragma once

#include <iostream>  // IWYU pragma: keep

#include "Animal.hpp"
#include "Colors.hpp"  // IWYU pragma: keep

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& src);
  ~Dog();

  Dog& operator=(const Dog& src);

  void makeSound() const;
};
