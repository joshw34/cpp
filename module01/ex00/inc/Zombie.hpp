#pragma once

#include <iostream> // IWYU pragma: keep
#include <string>

class Zombie {
 public:
  Zombie(std::string name);
  ~Zombie();
  void announce(void);

 private:
  std::string name;
};
