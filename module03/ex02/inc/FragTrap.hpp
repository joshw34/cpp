#pragma once

#include <iostream>  // IWYU pragma: keep

#include "ClapTrap.hpp"
#include "Colors.hpp"  // IWYU pragma: keep

class FragTrap : public ClapTrap {
 public:
  FragTrap();
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& src);
  ~FragTrap();

  FragTrap& operator=(const FragTrap& src);
  void attack(const std::string& target);

  void highFiveGuys();
};
