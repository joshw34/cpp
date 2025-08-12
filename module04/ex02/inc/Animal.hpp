#pragma once

#include <iostream>  // IWYU pragma: keep
#include <string>

#include "Colors.hpp"  // IWYU pragma: keep

class Animal {
 public:
  Animal();
  Animal(const Animal& src);
  virtual ~Animal();

  Animal& operator=(const Animal& src);

  virtual void makeSound() const = 0;

  const std::string& getType() const;

 protected:
  Animal(const std::string& newType);
  std::string type;
};
