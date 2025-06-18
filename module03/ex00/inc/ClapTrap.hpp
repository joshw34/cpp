#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream> // IWYU pragma: keep

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap& src);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& src);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string name;
		int hp;
		int energy;
		int damage;
};

#endif
