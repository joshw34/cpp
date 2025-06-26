#include "../inc/Character.hpp"

Character::Character() : name("defaultName") {
	std::cout << BOLD << "Default Character Constructor called" << RESET << std::endl; 
	initSpellArray(this->spells);
}

Character::Character(const std::string& name) : name(name) {
	std::cout << BOLD << "Character Constructor called for " << name << RESET << std::endl;
	initSpellArray(this->spells);
}

Character::Character(const Character& src) : name(src.name) {
	std::cout << BOLD << "Character Copy Constructor called to copy " << src.name << RESET << std::endl;
	copySpellArray(this->spells, src.spells);
}

Character::~Character() {
	std::cout << BOLD << "Character Destructor called for " << this->name << RESET << std::endl;
	clearSpellArray(spells);
}

Character& Character::operator=(const Character& src) {
	if (this != &src) {
		clearSpellArray(spells);
		copySpellArray(spells, src.spells);
		this->name = src.name;
	}
	return *this;
}

void Character::initSpellArray(AMateria* spells[]) {
	for(int i = 0; i < matMax; i++) {
		spells[i] = nullptr;
	}
}

void Character::copySpellArray(AMateria* spells[], AMateria* const src[]) {
	for(int i = 0; i < matMax; i++) {
		if (!src[i])
			spells[i] = nullptr;
		else
			spells[i] = src[i]->clone();
	}
}

void Character::clearSpellArray(AMateria* spells[]) {
	for (int i = 0; i < matMax; i++) {
		if (spells[i]) {
			delete spells[i];
			spells[i] = nullptr;
		}
	}
}
