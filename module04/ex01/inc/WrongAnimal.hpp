#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream> // IWYU pragma: keep

#define RED "\033[31m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& src);
		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& src);

		void makeSound() const;

		const std::string& getType() const;

	protected:
		WrongAnimal(const std::string& newType);
		std::string type;
};

#endif
