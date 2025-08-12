#include "../inc/Character.hpp"

Character::Character() : name("defaultName"), droppedMateria(NULL) {
  // std::cout << BOLD << "Default Character Constructor called" << RESET <<
  // std::endl;
  initMatArray(this->materia);
}

Character::Character(const std::string& name)
    : name(name), droppedMateria(NULL) {
  // std::cout << BOLD << "Character Constructor called for " << name << RESET
  // << std::endl;
  initMatArray(this->materia);
}

Character::Character(const Character& src)
    : name(src.name), droppedMateria(NULL) {
  // std::cout << BOLD << "Character Copy Constructor called to copy " <<
  // src.name << RESET << std::endl;
  copyMatArray(this->materia, src.materia);
}

Character::~Character() {
  // std::cout << BOLD << "Character Destructor called for " << this->name <<
  // RESET << std::endl;
  clearMatArray(materia);
  clearDroplist(this->droppedMateria);
}

Character& Character::operator=(const Character& src) {
  if (this != &src) {
    clearMatArray(materia);
    copyMatArray(materia, src.materia);
    this->name = src.name;
  }
  return *this;
}

const std::string& Character::getName() const {
  return this->name;
}

void Character::equip(AMateria* m) {
  if (!m)
    return;
  for (int i = 0; i < matMax; i++) {
    if (this->materia[i] == NULL) {
      this->materia[i] = m;
      return;
    }
  }
  addToDroplist(this->droppedMateria, m);
}

void Character::unequip(int idx) {
  if (!checkIdx(idx) || !this->materia[idx])
    return;
  addToDroplist(this->droppedMateria, this->materia[idx]);
  this->materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (!checkIdx(idx) || !this->materia[idx])
    return;
  this->materia[idx]->use(target);
}

void Character::initMatArray(AMateria* materia[]) {
  for (int i = 0; i < matMax; i++) {
    materia[i] = NULL;
  }
}

void Character::copyMatArray(AMateria* materia[], AMateria* const src[]) {
  for (int i = 0; i < matMax; i++) {
    if (!src[i])
      materia[i] = NULL;
    else
      materia[i] = src[i]->clone();
  }
}

void Character::clearMatArray(AMateria* materia[]) {
  for (int i = 0; i < matMax; i++) {
    if (materia[i]) {
      delete materia[i];
      materia[i] = NULL;
    }
  }
}

bool Character::checkIdx(int idx) {
  return idx >= 0 && idx < matMax;
}

Character::s_droplist::s_droplist(AMateria* m)
    : materia(m), next(NULL) {
        // std::cout << ITALIC << m->getType() << " added to droppedMateria" <<
        // RESET << std::endl;
      };

void Character::addToDroplist(s_droplist*& droppedMateria, AMateria* m) {
  s_droplist* node = new s_droplist(m);
  node->next = droppedMateria;
  droppedMateria = node;
}

void Character::clearDroplist(s_droplist*& droppedMateria) {
  if (!droppedMateria)
    return;

  // std::cout << ITALIC << "Deleting droppedMateria" << RESET << std::endl;

  s_droplist* next_node;

  while (droppedMateria) {
    next_node = droppedMateria->next;
    delete droppedMateria->materia;
    delete droppedMateria;
    droppedMateria = next_node;
  }
}
