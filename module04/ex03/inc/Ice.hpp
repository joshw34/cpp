#ifndef ICE_HPP
#define ICE_HPP

#include <iostream> // IWYU pragma: keep
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp" // IWYU pragma: keep

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& src);
		~Ice();

		Ice& operator=(const Ice& src);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
