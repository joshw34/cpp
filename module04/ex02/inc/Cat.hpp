#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
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

		const std::string& getIdea(int index) const;
		void printIdea(int index) const;
		void setIdea(int index, const std::string& newIdea);

	private:
		Brain* brain;
};

#endif
