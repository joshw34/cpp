#include "../inc/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << BOLD << "Cat Default Constructor called" << RESET << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << BOLD << "Cat Copy constructor called" << RESET << std::endl;
	this->brain  = new Brain(*src.brain);
}

Cat::~Cat() {
	std::cout << BOLD << "Cat Destructor called" << RESET << std::endl;
	delete this->brain;
}

Cat& Cat::operator=(const Cat& src) {
	if (this != &src) {
		this->Animal::operator=(src);
		*this->brain = *src.brain;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << GREEN << this->type << ": Meow!" << RESET << std::endl;
}

const std::string& Cat::getIdea(int index) const {
	return this->brain->getIdea(index); 
}

void Cat::printIdea(int index) const {
	return this->brain->printIdea(index, this->type);
}

void Cat::setIdea(int index, const std::string& newIdea) {
	return this->brain->setIdea(index, newIdea);
}

