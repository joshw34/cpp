#pragma once

#include <iostream> // IWYU pragma: keep
#include <string>

class Zombie {
 public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void announce(void);
  void setName(std::string name);

 private:
  std::string name;
};
