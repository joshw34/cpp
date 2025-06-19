#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hp(100), energy(50), damage(20), maxHp(100) {
	std::cout << BOLD << "ClapTrap Default Constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hp(100), energy(50), damage(20), maxHp(100) {
	std::cout << BOLD << "ClapTrap Constructor called for: " << name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) : name(src.name), hp(src.hp), energy(src.energy), damage(src.damage), maxHp(src.maxHp) {
	std::cout << BOLD << "ClapTrap Copy Constructor Called to copy " << this->name << RESET << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << BOLD << "ClapTrap Destructor Called for " << this->name << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	if (this != &src) {
		this->name = src.name;
		this->hp = src.hp;
		this->energy = src.energy;
		this->damage = src.damage;
		this->maxHp = src.maxHp;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
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

void ClapTrap::takeDamage(unsigned int amount) {
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

void ClapTrap::beRepaired(unsigned int amount) {
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

void ClapTrap::printStatus() const {
	std::cout << "[Name: " << this->name << ", HP: " << this->hp << ", Energy: " << this->energy << "]" <<std::endl; 
}
