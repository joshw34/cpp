#include "../inc/Zombie.hpp"

int	main(void) {
	std::string	zombieName;

	std::cout << "Enter Zombie Name: ";
	std::cin >> zombieName ;
	std::cout << std::endl;

	Zombie	newZomb(zombieName);
}
