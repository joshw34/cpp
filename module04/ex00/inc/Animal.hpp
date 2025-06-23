#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream> // IWYU pragma: keep

#define RED "\033[31m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class Animal {
	public:
		Animal();
		Animal(const Animal& src);
		virtual ~Animal();

		Animal& operator=(const Animal& src);

		virtual void makeSound() const;

		const std::string& getType() const;

	protected:
		Animal(const std::string& newType);
		std::string type;
};

#endif
