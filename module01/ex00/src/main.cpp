#include "../inc/Zombie.hpp"

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

int	main(void) {
	Zombie* z = newZombie("heap zombie");
	z->announce();
	randomChump("stack zombie");
	delete z;
}
