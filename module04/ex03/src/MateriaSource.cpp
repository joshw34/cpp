#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource() {
  // std::cout << BOLD << "MateriaSource Default Constructor called" << RESET <<
  // std::endl;
  initMatArray(this->materia);
}

MateriaSource::MateriaSource(const MateriaSource& src) {
  // std::cout << BOLD << "MateriaSource Copy Constructor called" << RESET <<
  // std::endl;
  copyMatArray(this->materia, src.materia);
}

MateriaSource::~MateriaSource() {
  // std::cout << BOLD << "MateriaSource Destructor called" << RESET <<
  // std::endl;
  clearMatArray(this->materia);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
  if (this != &src) {
    clearMatArray(this->materia);
    copyMatArray(this->materia, src.materia);
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
  if (!m)
    return;
  for (int i = 0; i < maxMat; i++) {
    if (!this->materia[i]) {
      this->materia[i] = m->clone();
      break;
    }
  }
  delete m;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
  for (int i = 0; i < maxMat; i++) {
    if (this->materia[i] && this->materia[i]->getType() == type)
      return this->materia[i]->clone();
  }
  return 0;
}

void MateriaSource::initMatArray(AMateria* materia[]) {
  for (int i = 0; i < maxMat; i++) {
    materia[i] = NULL;
  }
}

void MateriaSource::copyMatArray(AMateria* materia[], AMateria* const src[]) {
  for (int i = 0; i < maxMat; i++) {
    if (src[i])
      materia[i] = src[i]->clone();
    else
      materia[i] = NULL;
  }
}

void MateriaSource::clearMatArray(AMateria* materia[]) {
  for (int i = 0; i < maxMat; i++) {
    if (materia[i]) {
      delete materia[i];
      materia[i] = NULL;
    }
  }
}
