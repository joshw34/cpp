#pragma once

#include <iostream>  // IWYU pragma: keep

#include "AMateria.hpp"
#include "Colors.hpp"  // IWYU pragma: keep
#include "ICharacter.hpp"

class Ice : public AMateria {
 public:
  Ice();
  Ice(const Ice& src);
  ~Ice();

  Ice& operator=(const Ice& src);

  AMateria* clone() const;
  void use(ICharacter& target);
};
