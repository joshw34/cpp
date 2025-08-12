#pragma once

#include <iostream> // IWYU pragma: keep
#include <string>

#include "./Weapon.hpp"

class HumanA {
 public:
  HumanA(std::string name, Weapon& w);
  ~HumanA();
  void attack();

 private:
  std::string name;
  Weapon& weaponRef;
};
