#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream> // IWYU pragma: keep

#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& src);
		~Cat();

		Cat& operator=(const Cat& src);

		void makeSound() const;
};

#endif
