#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream> // IWYU pragma: keep

#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class DiamondTrap : public ScavTrap, public FragTrap {

};

#endif
