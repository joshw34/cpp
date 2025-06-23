#include "../inc/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << BOLD << "Cat Default Constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << BOLD << "Cat Copy constructor called" << RESET << std::endl;
}

Cat::~Cat() {
	std::cout << BOLD << "Cat Destructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
	if (this != &src) {
		this->Animal::operator=(src);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << GREEN << this->type << ": Meow!" << RESET << std::endl;
}

