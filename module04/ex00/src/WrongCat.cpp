#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << BOLD << "WrongCat Default Constructor called" << RESET
            << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
  std::cout << BOLD << "WrongCat Copy constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << BOLD << "WrongCat Destructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
  if (this != &src) {
    this->WrongAnimal::operator=(src);
  }
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << GREEN << this->type << ": Meow!" << RESET << std::endl;
}
