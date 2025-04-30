#include "../inc/Zombie.hpp"

Zombie::Zombie() {
	name = "Unnamed Zombie";
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
std::cout << name << " is dead again" << std::endl;
}

void	Zombie::announce() {
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->name = name;
}
