#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main() {
  {
    FragTrap a("A");
    a.printStatus();
    std::cout << std::endl;

    FragTrap b;
    b.printStatus();
    std::cout << std::endl;

    std::cout << "default = a" << std::endl;
    b = a;
    b.printStatus();
    std::cout << std::endl;

    FragTrap c(a);
    c.printStatus();
    std::cout << std::endl;
  }
  std::cout << "\n************************\n" << std::endl;
  {
    FragTrap frag("Frag");
    frag.printStatus();
    std::cout << std::endl;

    ScavTrap scav("Scav");
    scav.printStatus();
    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
      scav.attack("Frag");
      frag.takeDamage(20);
      scav.printStatus();
      frag.printStatus();
      std::cout << std::endl;
      frag.attack("Scav");
      scav.takeDamage(30);
      scav.printStatus();
      frag.printStatus();
      std::cout << std::endl;
    }
    frag.highFiveGuys();
    std::cout << std::endl;
  }
}
