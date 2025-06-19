#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

#define SPACE std::cout << std::endl;
#define WRITE std::cout <<
#define END << std::endl;

int main() {
	{
		FragTrap a("A");
		a.printStatus();
		SPACE

		FragTrap b;
		b.printStatus();
		SPACE

		WRITE "default = a" END
		b = a;
		b.printStatus();
		SPACE

		FragTrap c(a);
		c.printStatus();
		SPACE
	}
	SPACE
	WRITE "************************" END
	SPACE
	{
		FragTrap frag("Frag");
		frag.printStatus();
		SPACE

		ScavTrap scav("Scav");
		scav.printStatus();
		SPACE

		for (int i = 0; i < 4; i++) {
			scav.attack("Frag");
			frag.takeDamage(20);
			scav.printStatus();
			frag.printStatus();
			SPACE
			frag.attack("Scav");
			scav.takeDamage(30);
			scav.printStatus();
			frag.printStatus();
			SPACE
		}
		frag.highFiveGuys();
		SPACE
	}
}
