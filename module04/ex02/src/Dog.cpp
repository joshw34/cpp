#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << BOLD << "Dog Default Constructor called" << RESET << std::endl;
  this->brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src) {
  std::cout << BOLD << "Dog Copy constructor called" << RESET << std::endl;
  this->brain = new Brain(*src.brain);
}

Dog::~Dog() {
  std::cout << BOLD << "Dog Destructor called" << RESET << std::endl;
  delete this->brain;
}

Dog& Dog::operator=(const Dog& src) {
  if (this != &src) {
    this->Animal::operator=(src);
    *this->brain = *src.brain;
  }
  return *this;
}

void Dog::makeSound() const {
  std::cout << GREEN << this->type << ": Woof!" << RESET << std::endl;
}

const std::string& Dog::getIdea(int index) const {
  return this->brain->getIdea(index);
}

void Dog::printIdea(int index) const {
  return this->brain->printIdea(index, this->type);
}

void Dog::setIdea(int index, const std::string& newIdea) {
  return this->brain->setIdea(index, newIdea);
}
