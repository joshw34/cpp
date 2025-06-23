#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream> // IWYU pragma: keep

#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& src);
		~Dog();

		Dog& operator=(const Dog& src);

		void makeSound() const;
};

#endif
