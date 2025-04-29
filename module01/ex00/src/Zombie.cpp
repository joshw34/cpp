#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
	announce();
}

Zombie::~Zombie() {
	std::cout << name << " is dead again" << std::endl;
}

void	Zombie::announce() {
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
