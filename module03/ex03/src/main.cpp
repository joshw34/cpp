#include "../inc/DiamondTrap.hpp"

int main() {
	{
		std::cout << "Default Constructor" << std::endl;
		DiamondTrap def;
		std::cout << std::endl;

		std::cout << "Name Constructor" << std::endl;
		DiamondTrap a("A");
		std::cout << std::endl;

		std::cout << "Copy Constructor:" << std::endl; 
		DiamondTrap b(a);
		std::cout << std::endl;

		std::cout << "Copy Operator (default = a)" << std::endl;
		def = a;
		std::cout << std::endl;
	}
	std::cout << "\n******************************\n" << std::endl;
	{
		DiamondTrap a("A");
		DiamondTrap b("B");
		std::cout << std::endl;

		a.printStatus();
		b.printStatus();
		std::cout << std::endl;

		a.guardGate();
		a.highFiveGuys();
		a.whoAmI();
		std::cout << std::endl;

		b.guardGate();
		b.highFiveGuys();
		b.whoAmI();
		std::cout << std::endl;

		a.attack("B");
		b.takeDamage(30);
		std::cout << std::endl;

		b.beRepaired(40);
		std::cout << std::endl;
	}
}
