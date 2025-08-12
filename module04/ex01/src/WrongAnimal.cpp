#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("defaultWrongAnimal") {
  std::cout << BOLD << "WrongAnimal Default Constructor called" << RESET
            << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : type(src.type) {
  std::cout << BOLD << "WrongAnimal Copy Constructor called to copy "
            << src.type << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << BOLD << "WrongAnimal Destructor called for " << this->type
            << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
  if (this != &src) {
    this->type = src.type;
  }
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << RED << this->type << " does not make a sound" << RESET
            << std::endl;
}

const std::string& WrongAnimal::getType() const {
  return this->type;
}

WrongAnimal::WrongAnimal(const std::string& newType) : type(newType) {
  std::cout << BOLD << "WrongAnimal Constructor called to create a " << newType
            << RESET << std::endl;
}
