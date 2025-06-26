#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
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

		const std::string& getIdea(int index) const;
		void printIdea(int index) const;
		void setIdea(int index, const std::string& newIdea);

	private:
		Brain* brain;
};

#endif
