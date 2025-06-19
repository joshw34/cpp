#include "../inc/ScavTrap.hpp"
#include <fstream>

#define SPACE std::cout << std::endl;
#define WRITE std::cout <<
#define END << std::endl;

int main() {
	{
		ScavTrap a("A");
		a.printStatus();
		SPACE

		ScavTrap b;
		b.printStatus();
		SPACE

		WRITE "default = a" END
		b = a;
		b.printStatus();
		SPACE

		ScavTrap c(a);
		c.printStatus();
		SPACE
	}
	SPACE
	WRITE "************************" END
	SPACE
	{
		ScavTrap a("A");
		a.printStatus();
		SPACE

		ScavTrap b("B");
		b.printStatus();
		SPACE

		ScavTrap c("C");
		c.printStatus();
		c.guardGate();
		SPACE

		a.attack("B");
		b.takeDamage(20);
		a.printStatus();
		b.printStatus();
		SPACE
		
		b.beRepaired(10);
		b.printStatus();
		SPACE

		for (int i = 0; i < 6; i++) {
			b.attack("A");
			a.takeDamage(20);
		}
		a.printStatus();
		b.printStatus();
		SPACE

		WRITE "B now has 0 energy points" END
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
		SPACE

		a.beRepaired(10);
		a.attack("B");
		a.printStatus();
		SPACE

		b.beRepaired(10);
		b.attack("A");
		b.takeDamage(1000);
		SPACE
	}
}
