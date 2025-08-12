#pragma once

#include <iostream>  // IWYU pragma: keep

#include "ClapTrap.hpp"
#include "Colors.hpp"  // IWYU pragma: keep

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& src);
  ~ScavTrap();

  ScavTrap& operator=(const ScavTrap& src);

  void attack(const std::string& target);
  void guardGate();
};
