#include "../inc/ClapTrap.hpp"

int main() {
	{
		ClapTrap a("A");
		a.printStatus();
		ClapTrap b(a);
		b.printStatus();
		std::cout << std::endl;

		ClapTrap c("C");
		c.printStatus();
		ClapTrap d;
		d.printStatus();
		
		std::cout << "\nAssignment Operator: default = C" << std::endl;
		d = c;
		c.printStatus();
		d.printStatus();
		std::cout << std::endl;
	}
	std::cout << "\n******************************\n" << std::endl;
	{
		ClapTrap a("A");
		a.printStatus();
		std::cout << std::endl;

		a.beRepaired(1);
		a.printStatus();
		std::cout << std::endl;
		
		a.attack("B");
		a.printStatus();
		std::cout << std::endl;

		a.takeDamage(8);
		a.printStatus();
		std::cout << std::endl;

		a.beRepaired(8);
		a.printStatus();
		std::cout << std::endl;

		a.takeDamage(9);
		a.printStatus();
		std::cout << std::endl;

		a.beRepaired(10);
		a.printStatus();
		std::cout << std::endl;

		for (int i = 0; i < 7; i++) {
			a.attack("B");
		}
		a.printStatus();
		std::cout << std::endl;

		a.attack(("B"));
		a.beRepaired((5));
		a.printStatus();
		std::cout << std::endl;

		a.takeDamage(10);
		a.printStatus();
		std::cout << std::endl;

		a.attack("B");
		a.beRepaired(10);
		a.takeDamage(10);
		std::cout << std::endl;
	}
}
