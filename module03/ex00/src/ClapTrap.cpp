#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hp(10), energy(10), damage(0) {
	std::cout << "Deafult Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hp(10), energy(10), damage(0) {
	std::cout << "Constructor called for: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) : name(src.name), hp(src.hp), energy(src.energy), damage(src.damage) {
	std::cout << "Copy Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap() {
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
	if (this != &src) {
		this->name = src.name;
		this->hp = src.hp;
		this->damage = src.damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << this->name;
	if (this->hp <= 0)
		std::cout << " cannot attack. He's dead" << std::endl;
	else if (this->energy <= 0)
		std::cout << " cannot attack. He has no Energy Points" << std::endl;
	else {
		std::cout << "attacks " << target << " causing " << this->damage << " points of damage" << std::endl; 
		this->energy--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->name;
	if (this->hp <= 0) {
		std::cout << " is already dead" << std::endl;
		return;
	}
	this->hp - amount < 0 ? this->hp = 0 : this->hp -= amount;
	std::cout << " took " << amount << " points of damage";
	if (this->hp == 0)
		std::cout << " and died";
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << this->name;
	if (this->hp == 0)
		std::cout << " cannot be repaired. He's dead" << std::endl;
	else if (this->energy == 0)
		std::cout << " cannot be repaired. He has no energy points" << std::endl;
	else if (this->hp == 10)
		std::cout << " cannot be repaired above 10hp" << std::endl;
	else {
		this->energy--;
		this->hp + amount > 10 ? this->hp = 10 : this->hp +=amount;
		std::cout << " was repaired to " << this->hp << "hp" << std::endl;
	}
}
