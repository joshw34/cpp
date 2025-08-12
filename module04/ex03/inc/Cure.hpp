#pragma once

#include <iostream>  // IWYU pragma: keep

#include "AMateria.hpp"
#include "Colors.hpp"  // IWYU pragma: keep
#include "ICharacter.hpp"

class Cure : public AMateria {
 public:
  Cure();
  Cure(const Cure& src);
  ~Cure();

  Cure& operator=(const Cure& src);

  AMateria* clone() const;
  void use(ICharacter& target);
};
