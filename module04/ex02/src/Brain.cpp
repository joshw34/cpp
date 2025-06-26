#include "../inc/Brain.hpp"

Brain::Brain() {
	std::cout << BOLD << "Brain Default Constructor called" << RESET <<std::endl;	
}

Brain::Brain(const Brain& src) {
	std::cout << BOLD << "Brain Copy Constructor called" << RESET <<std::endl;	
	for(int i = 0; i < brainSize; i++) {
		this->ideas[i] = src.ideas[i];
	}
}

Brain::~Brain() {
	std::cout << BOLD << "Brain Destructor called" << RESET <<std::endl;	
}

Brain& Brain::operator=(const Brain& src) {
	if (this != &src) {
		for(int i = 0; i < brainSize; i++) {
			this->ideas[i] = src.ideas[i];
		}
	}
	return *this;
}

const std::string& Brain::getIdea(int index) const {
	if (index < 0 || index >= this->brainSize) {
		std::cerr << RED << "Error: " << index << "is Out of Range. Returning ideas[0]" << RESET << std::endl;
		return this->ideas[0];
	}
	return this->ideas[index];
}

void Brain::printIdea(int index, const std::string& type) const {
	if (index < 0 || index >= this->brainSize) {
		std::cerr << RED << "Error: " << index << "is Out of Range" << RESET << std::endl;
		return;
	}
	std::cout << YELLOW << type << ": " << this->ideas[index] << RESET << std::endl;
}

void Brain::setIdea(int index, const std::string& newIdea) {
	if (index < 0 || index >= this->brainSize) {
		std::cerr << RED << "Error: " << index << " is Out of Range." << RESET << std::endl;
		return;
	}
	this->ideas[index] = newIdea;	
}

