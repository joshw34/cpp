#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) {
	std::cout << "creating zombie named: " << name << std::endl;
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << name << " destroyed" << std::endl;
}
