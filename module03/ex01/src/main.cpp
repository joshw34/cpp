#include "../inc/ScavTrap.hpp"
#include <fstream>

int main() {
	{
		ScavTrap a("A");
		a.printStatus();
		std::cout << std::endl;

		ScavTrap b;
		b.printStatus();
		std::cout << std::endl;

		std::cout << "default = a" << std::endl;
		b = a;
		b.printStatus();
		std::cout << std::endl;

		ScavTrap c(a);
		c.printStatus();
		std::cout << std::endl;
	}
	std::cout << "\n************************\n" << std::endl;
	{
		ScavTrap a("A");
		a.printStatus();
		std::cout << std::endl;

		ScavTrap b("B");
		b.printStatus();
		std::cout << std::endl;

		ScavTrap c("C");
		c.printStatus();
		c.guardGate();
		std::cout << std::endl;

		a.attack("B");
		b.takeDamage(20);
		a.printStatus();
		b.printStatus();
		std::cout << std::endl;
		
		b.beRepaired(10);
		b.printStatus();
		std::cout << std::endl;

		for (int i = 0; i < 6; i++) {
			b.attack("A");
			a.takeDamage(20);
		}
		a.printStatus();
		b.printStatus();
		std::cout << std::endl;

		std::cout << "B now has 0 energy points" << std::endl;
		std::ofstream null_stream("/dev/null");
		std::streambuf* orig = std::cout.rdbuf();
		std::cout.rdbuf(null_stream.rdbuf());
		for(int i = 0; i < 44; i++) {
			b.attack("A");
			a.takeDamage(20);
		}
		std::cout.rdbuf(orig);
		a.printStatus();
		b.printStatus();
		std::cout << std::endl;

		a.beRepaired(10);
		a.attack("B");
		a.printStatus();
		std::cout << std::endl;

		b.beRepaired(10);
		b.attack("A");
		b.takeDamage(1000);
		std::cout << std::endl;
	}
}
