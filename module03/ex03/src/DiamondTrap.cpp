#include "../inc/DiamondTrap.hpp"

/* Only one set of member variables exist for shared variables (virtual inheritance from ClapTrap).
   They will be set to the defaults of the last constructor (FragTrap).
   this->energy must be overridden to match ScavTrap. */
DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap() {
	std::cout << BOLD << "DiamondTrap Default Constructor called" << RESET << std::endl;
	this->name = "default";
	this->energy = 50;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name") , ScavTrap() , FragTrap() {
	std::cout << BOLD << "DiamondTrap Constructor called for " << name << RESET << std::endl;
	this->name = name;
	this->energy = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src.ClapTrap::name), ScavTrap(), FragTrap() {
	std::cout << BOLD << "DiamondTrap Copy Constructor called to copy " << src.name << RESET <<std::endl;
	this->name = src.name;
	this->hp = src.hp;
	this->energy = src.energy;
	this->damage = src.damage;
	this->maxHp = src.maxHp;
}

DiamondTrap::~DiamondTrap() {
	std::cout << BOLD << "DiamondTrap Destructor called for " << this->name << RESET << std::endl;
}

/* this->name not assigned by ClapTrap operator= as it is a DiamondTrap private member */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
	if (this != &src) {
		ClapTrap::operator=(src);
		this->name = src.name;
	}
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << GREEN
		      << "DiamondTrap name: " << this->name
	          << "\nClapTrap name: " << ClapTrap::name
	          << RESET << std::endl;
}

void DiamondTrap::printStatus() const {
	std::cout << "[Name: " << this->name << ", HP: " << this->hp << ", Energy: " << this->energy << "]" <<std::endl; 
}
