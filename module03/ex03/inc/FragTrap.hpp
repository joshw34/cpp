#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream> // IWYU pragma: keep

#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& src);
		~FragTrap();

		FragTrap& operator=(const FragTrap& src);

		void highFiveGuys();
};

#endif
