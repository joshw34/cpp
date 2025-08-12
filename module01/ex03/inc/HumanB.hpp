#pragma once

#include <iostream> // IWYU pragma: keep
#include <string>

#include "./Weapon.hpp"

class HumanB {
 public:
  HumanB(std::string name);
  ~HumanB();
  void setWeapon(Weapon& w);
  void attack();

 private:
  std::string name;
  Weapon* weaponPtr;
};
