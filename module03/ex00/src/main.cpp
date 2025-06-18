#include "../inc/ClapTrap.hpp"

#define SPACE std::cout << std::endl;

int main() {
	{
		ClapTrap a("A");
		a.printStatus();
		ClapTrap b(a);
		b.printStatus();
		SPACE

		ClapTrap c("C");
		c.printStatus();
		ClapTrap d;
		d.printStatus();
		
		std::cout << "\nAssignment Operator: default = C" << std::endl;
		d = c;
		c.printStatus();
		d.printStatus();
		SPACE
	}
	std::cout << "\n" << std::endl;
	{
		ClapTrap a("A");
		a.printStatus();
		SPACE

		a.beRepaired(1);
		a.printStatus();
		SPACE
		
		a.attack("B");
		a.printStatus();
		SPACE

		a.takeDamage(8);
		a.printStatus();
		SPACE

		a.beRepaired(8);
		a.printStatus();
		SPACE

		a.takeDamage(9);
		a.printStatus();
		SPACE

		a.beRepaired(10);
		a.printStatus();
		SPACE

		for (int i = 0; i < 7; i++) {
			a.attack("B");
		}
		a.printStatus();
		SPACE

		a.attack(("B"));
		a.beRepaired((5));
		a.printStatus();
		SPACE

		a.takeDamage(10);
		a.printStatus();
		SPACE

		a.attack("B");
		a.beRepaired(10);
		a.takeDamage(10);
		SPACE
	}
}
