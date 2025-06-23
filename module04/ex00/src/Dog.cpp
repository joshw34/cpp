#include "../inc/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << BOLD << "Dog Default Constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {
	std::cout << BOLD << "Dog Copy constructor called" << RESET << std::endl;
}

Dog::~Dog() {
	std::cout << BOLD << "Dog Destructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
	if (this != &src) {
		this->Animal::operator=(src);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << GREEN << this->type << ": Woof!" << RESET << std::endl;
}

