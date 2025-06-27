#include "../inc/AMateria.hpp"

AMateria::AMateria() : type("defaultType") {
	//std::cout << BOLD << "AMateria Default Constructor called" << RESET << std::endl;
}

AMateria::AMateria(const std::string& type) : type(type) {
	//std::cout << BOLD << "AMateria Constructor called for " << type << RESET << std::endl;
}

AMateria::AMateria(const AMateria& src) : type(src.type) {
	//std::cout << BOLD << "AMateria Copy Constructor called to copy " << type << RESET << std::endl;
}

AMateria::~AMateria() {
	//std::cout << BOLD << "AMateria Destructor called for " << this->type << RESET << std::endl;
}

/* No self assignment check as we don't assign type. */
AMateria& AMateria::operator=(const AMateria& src) {
	(void)src;
	return *this;
}

const std::string& AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << RED << "AMateria has nothing to use" << RESET << std::endl;
}
