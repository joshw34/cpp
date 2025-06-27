#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice") {
	//std::cout << BOLD << "Ice Default Constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice& src) : AMateria(src) {
	//std::cout << BOLD << "Ice Copy Constructor called" << RESET << std::endl;
}

Ice::~Ice() {
	//std::cout << BOLD << "Ice Destructor called" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& src) {
	(void)src;
	return *this;
}

AMateria* Ice::clone() const {
	AMateria* new_ice = new Ice(*this);
	return new_ice;
} 

void Ice::use(ICharacter& target) {
	std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl; 
}
