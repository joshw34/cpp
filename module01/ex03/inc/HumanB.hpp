#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "../inc/Weapon.hpp"
#include <string>
#include <iostream>

class	HumanB {
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon& w);
		void	attack();

	private:
		std::string name;
		Weapon* weaponPtr;
};

#endif
