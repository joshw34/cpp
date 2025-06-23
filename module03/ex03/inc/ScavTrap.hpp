#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream> // IWYU pragma: keep

#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& src);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& src);

		void guardGate();
};
#endif
