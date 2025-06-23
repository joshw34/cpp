#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream> // IWYU pragma: keep

#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& src);
		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& src);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void guardGate();
		void highFiveGuys();
		void whoAmI();

		void printStatus() const;

	private:
		std::string name;

};

#endif
