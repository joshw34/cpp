#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << BOLD << "ScavTrap Default Constructor called" << RESET << std::endl; 
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << BOLD << "ScavTrap Constructor called for " << name << RESET << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
	std::cout << BOLD << "ScavTrap Copy Constructor called to copy " << src.name << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << BOLD << "ScavTrap Destructor Called for " << this->name << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
	if (this != &src) {
		ClapTrap::operator=(src);
	}
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << GREEN << this->name << " is now in Gate Keeper mode" << RESET << std::endl;
}
