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

void FragTrap::attack(const std::string& target) {
	std::cout << "FragTrap " << this->name;
	if (this->hp <= 0)
		std::cout << RED << " cannot attack: 0hp" << RESET << std::endl;
	else if (this->energy <= 0)
		std::cout << RED << " cannot attack: 0 energy points" << RESET << std::endl;
	else {
		std::cout << GREEN << " attacks " << target << ", causing " << this->damage << " points of damage" << RESET << std::endl; 
		this->energy--;
	}
}

void FragTrap::highFiveGuys() {
	std::cout << GREEN << this->name << ": High Five Guys!" << RESET << std::endl;
}
