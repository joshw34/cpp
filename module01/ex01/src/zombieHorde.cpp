#include "../inc/Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {
	Zombie* z = new Zombie[n];

	for (int i = 0; i < n; ++i) {
		z[i].setName(name);
	}
	return z;
}
