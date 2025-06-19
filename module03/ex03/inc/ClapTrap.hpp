#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream> // IWYU pragma: keep

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW  "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& src);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& src);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void printStatus() const;

	protected:
		std::string name;
		int hp;
		int energy;
		int damage;
		int maxHp;
};

#endif
