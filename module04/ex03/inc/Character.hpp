#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream> // IWYU pragma: keep
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Colors.hpp" // IWYU pragma: keep

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
		AMateria* spells[matMax];
		static void initSpellArray(AMateria* spells[]);
		static void copySpellArray(AMateria* spells[], AMateria* const src[]);
		static void clearSpellArray(AMateria* spells[]);

};

#endif
