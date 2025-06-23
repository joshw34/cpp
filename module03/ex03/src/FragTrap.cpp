#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << BOLD << "FragTrap Default Constructor called" << RESET << std::endl;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << BOLD << "FragTrap Constructor called for " << name << RESET << std::endl;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
	std::cout << BOLD << "FragTrap Copy Constructor called to copy " << src.name << RESET << std::endl;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::~FragTrap() {
	std::cout << BOLD << "FragTrap Destructor called for " << this->name << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
	if (this != &src){ 
		ClapTrap::operator=(src);
		this->energy = 100;
		this->damage = 30;
	}
	return *this;
}

void FragTrap::highFiveGuys() {
	std::cout << GREEN << this->name << ": High Five Guys!" << RESET << std::endl;
}
