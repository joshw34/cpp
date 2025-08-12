#pragma once

#include <iostream>  // IWYU pragma: keep

#include "Colors.hpp"  // IWYU pragma: keep

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
