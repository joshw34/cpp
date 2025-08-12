#pragma once

#include <iostream>  // IWYU pragma: keep
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Colors.hpp"  // IWYU pragma: keep

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& src);
  ~Dog();

  Dog& operator=(const Dog& src);

  void makeSound() const;

  const std::string& getIdea(int index) const;
  void printIdea(int index) const;
  void setIdea(int index, const std::string& newIdea);

 private:
  Brain* brain;
};
