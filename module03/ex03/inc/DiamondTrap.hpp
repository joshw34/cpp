#pragma once

#include <iostream>  // IWYU pragma: keep

#include "Colors.hpp"  // IWYU pragma: keep
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap();
  DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& src);
  ~DiamondTrap();

  DiamondTrap& operator=(const DiamondTrap& src);

  using ScavTrap::attack;

  void whoAmI();

  void printStatus() const;

 private:
  std::string name;
};
