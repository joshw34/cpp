#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
	this->weaponPtr = NULL;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& w) {
	this->weaponPtr = &w;
}

void	HumanB::attack() {
	std::cout << name << " attacks with their ";
	if (this->weaponPtr) {
		std::cout << this->weaponPtr->getType() << std::endl;
	}
	else {
		std::cout << "nothing" << std::endl;
	}
}
