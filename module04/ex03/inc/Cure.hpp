#ifndef CURE_HPP
#define CURE_HPP

#include <iostream> // IWYU pragma: keep
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Colors.hpp" // IWYU pragma: keep

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& src);
		~Cure();

		Cure& operator=(const Cure& src);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
