#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream> // IWYU pragma: keep
#include "Colors.hpp" // IWYU pragma: keep

class ICharacter;

class AMateria {
	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& src);
		virtual ~AMateria();

		AMateria& operator=(const AMateria& src);

		const std::string& getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string type;
};

#endif
