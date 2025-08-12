#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure") {
  // std::cout << BOLD << "Cure Default Constructor called" << RESET <<
  // std::endl;
}

Cure::Cure(const Cure& src) : AMateria(src) {
  // std::cout << BOLD << "Cure Copy Constructor called" << RESET << std::endl;
}

Cure::~Cure() {
  // std::cout << BOLD << "Cure Destructor called" << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& src) {
  (void)src;
  return *this;
}

AMateria* Cure::clone() const {
  AMateria* new_ice = new Cure(*this);
  return new_ice;
}

void Cure::use(ICharacter& target) {
  std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << RESET
            << std::endl;
}
