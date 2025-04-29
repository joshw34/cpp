#include "../inc/Zombie.hpp"

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

int	main(void) {
	std::string	name;

	std::cout << "Enter First Zombie Name: ";
	std::cin >> name ;
	std::cout << std::endl;

	randomChump(name);

	Zombie* z = newZombie(name);
	delete z;
}
