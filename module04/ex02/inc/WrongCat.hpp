#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>  // IWYU pragma: keep

#include "WrongAnimal.hpp"

#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat& src);
  ~WrongCat();

  WrongCat& operator=(const WrongCat& src);

  void makeSound() const;
};

#endif
