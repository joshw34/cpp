#pragma once

#include <iostream>  // IWYU pragma: keep
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Colors.hpp"  // IWYU pragma: keep

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat& src);
  ~Cat();

  Cat& operator=(const Cat& src);

  void makeSound() const;

  const std::string& getIdea(int index) const;
  void printIdea(int index) const;
  void setIdea(int index, const std::string& newIdea);

 private:
  Brain* brain;
};
