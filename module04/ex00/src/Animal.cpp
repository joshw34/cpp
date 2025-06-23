#include "../inc/Animal.hpp"

Animal::Animal() : type("defaultAnimal") {
	std::cout << BOLD << "Animal Default Constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& src) : type(src.type) {
	std::cout << BOLD << "Animal Copy Constructor called to copy " << src.type << RESET << std::endl;
}

Animal::~Animal() {
	std::cout << BOLD << "Animal Destructor called for " << this->type << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& src) {
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}

void Animal::makeSound() const {
	std::cout << RED << this->type << " does not make a sound" << RESET << std::endl;
}

const std::string& Animal::getType() const {
	return this->type;
}

Animal::Animal(const std::string& newType) : type(newType){
	std::cout << BOLD << "Animal Constructor called to create a " << newType << RESET << std::endl;
}
