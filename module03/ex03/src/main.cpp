#include "../inc/DiamondTrap.hpp"

#define SPACE std::cout << std::endl;
#define WRITE std::cout <<
#define END << std::endl;

int main() {
	{
		WRITE "Default Constructor" END
		DiamondTrap def;
		SPACE

		WRITE "Name Constructor" END
		DiamondTrap a("A");
		SPACE

		WRITE "Copy Constructor:" END 
		DiamondTrap b(a);
		SPACE

		WRITE "Copy Operator (default = a)" END
		def = a;
		SPACE
	}
	SPACE WRITE "******************************" END SPACE
	{
		DiamondTrap a("A");
		DiamondTrap b("B");
		SPACE

		a.printStatus();
		b.printStatus();
		SPACE

		a.guardGate();
		a.highFiveGuys();
		a.whoAmI();
		SPACE

		b.guardGate();
		b.highFiveGuys();
		b.whoAmI();
		SPACE

		a.attack("B");
		b.takeDamage(30);
		SPACE

		b.beRepaired(40);
		SPACE
	}
}
