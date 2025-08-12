#include "../inc/Zombie.hpp"

Zombie* zombieHorde(int n, std::string name);

static void input(int& n, std::string& name) {
  std::cout << "How many zombies?: ";
  std::cin >> n;
  std::cout << std::endl;

  std::cout << "Zombie Name?: ";
  std::cin >> name;
  std::cout << std::endl;
}

int main(void) {
  int n;
  std::string name;

  input(n, name);
  Zombie* horde = zombieHorde(n, name);
  for (int i = 0; i < n; ++i) {
    horde[i].announce();
  }
  delete[] horde;
}
