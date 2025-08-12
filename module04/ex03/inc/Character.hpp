#pragma once

#include <iostream>  // IWYU pragma: keep
#include <string>

#include "AMateria.hpp"
#include "Colors.hpp"  // IWYU pragma: keep
#include "ICharacter.hpp"

class Character : public ICharacter {
 public:
  Character();
  Character(const std::string& name);
  Character(const Character& src);
  ~Character();

  Character& operator=(const Character& src);

  const std::string& getName() const;
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);

 private:
  std::string name;
  static const int matMax = 4;
  AMateria* materia[matMax];

  struct s_droplist {
    AMateria* materia;
    s_droplist* next;
    s_droplist(AMateria* m);
  };

  static void initMatArray(AMateria* materia[]);
  static void copyMatArray(AMateria* materia[], AMateria* const src[]);
  static void clearMatArray(AMateria* materia[]);
  static bool checkIdx(int idx);

  s_droplist* droppedMateria;
  static void addToDroplist(s_droplist*& droppedMateria, AMateria* m);
  static void clearDroplist(s_droplist*& droppedMateria);
};
