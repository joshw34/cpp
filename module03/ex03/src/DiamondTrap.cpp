#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap() {
	std::cout << BOLD << "DiamondTrap Default Constructor called" << RESET << std::endl;
	this->name = "default";
	this->hp = 100;
	this->energy = 50;
	this->damage = 30;
	this->maxHp = 100;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name") , ScavTrap() , FragTrap() {
	std::cout << BOLD << "DiamondTrap Constructor called for " << name << RESET << std::endl;
	this->name = name;
	this->hp = 100;
	this->energy = 50;
	this->damage = 30;
	this->maxHp = 100;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src.name + "_clap_name"), ScavTrap(), FragTrap() {
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


void DiamondTrap::attack(const std::string& target) {
	std::cout << this->name;
	if (this->hp <= 0)
		std::cout << RED << " cannot attack: 0hp" << RESET << std::endl;
	else if (this->energy <= 0)
		std::cout << RED << " cannot attack: 0 energy points" << RESET << std::endl;
	else {
		std::cout << GREEN << " attacks " << target << ", causing " << this->damage << " points of damage" << RESET << std::endl; 
		this->energy--;
	}
}

void DiamondTrap::takeDamage(unsigned int amount) {
	std::cout << this->name;
	if (this->hp <= 0) {
		std::cout << RED << " is already dead" << RESET << std::endl;
		return;
	}
	this->hp -= amount;
	if (this->hp < 0)
		this->hp = 0;
	std::cout << YELLOW << " took " << amount << " points of damage";
	if (this->hp == 0)
		std::cout << " and died";
	std::cout << RESET << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
	std::cout << this->name;
	if (this->hp == 0)
		std::cout << RED << " cannot be repaired: 0hp" << RESET << std::endl;
	else if (this->energy == 0)
		std::cout << RED << " cannot be repaired: 0 energy points" << RESET << std::endl;
	else if (this->hp == this->maxHp)
		std::cout << RED << " cannot be repaired above " << this->maxHp << "hp" << RESET << std::endl;
	else {
		this->energy--;
		this->hp += amount;
		if (this->hp > this->maxHp)
			this->hp = this->maxHp;
		std::cout << GREEN << " was repaired to " << this->hp << "hp" << RESET << std::endl;
	}
}
/* Overload required for guardGate and highFiveGuys as the inherited version uses _clap_name */
void DiamondTrap::guardGate() {
	std::cout << GREEN << this->name << " is now in Gate Keeper mode" << RESET << std::endl;
}

void DiamondTrap::highFiveGuys() {
	std::cout << GREEN << this->name << ": High Five Guys!" << RESET << std::endl;
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
