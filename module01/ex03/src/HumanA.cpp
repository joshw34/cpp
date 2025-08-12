#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& w) : name(name), weaponRef(w) {}

HumanA::~HumanA() {}

void HumanA::attack() {
  std::cout << this->name << " attacks with their " << this->weaponRef.getType()
            << std::endl;
}
