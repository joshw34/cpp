#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main () {
	{
		/* Virtual keyword checks for object type at runtime and selects the relevant makeSound().
		   Virtual destructor ensures derived destructors are called even though we use a base class pointer */

		std::cout << "TESTS FROM SUBJECT PDF:\n" << std::endl;
		
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;

		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;
		
		meta->makeSound();
		i->makeSound();
		j->makeSound();
		std::cout << std::endl;
		
		delete i;
		delete j;
		delete meta;
	}
	std::cout << "\n******************************\n" << std::endl;	
	{
		/* Without the virtual keyword, these objects will use WrongAnimal::makeSound() even if they are WrongCat objects.
		   Without virtual destructor, only WrongAnimal::~WrongAnimal() is called, regardless of object type.
		   This is decided at compile time based on the pointer type not the object type pointer references */

		std::cout << "TESTS FROM SUBJECT PDF (WRONGANIMAL / WRONGCAT):\n" << std::endl;
		
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		
		std::cout << i->getType() << " " << std::endl;
		
		i->makeSound();
		meta->makeSound();
		
		delete i;
		delete meta;
	}
	std::cout << "\n******************************\n" << std::endl;	
	{
		/* Only one instance of Animal, Dog and Cat are created. An Animal pointer in the array then points to each.
		   This allows Dog/Cat member access via Animal pointer. */

		std::cout << "ARRAY OF ANIMAL*:\n" << std::endl;

		Animal* zoo[3] = {new Animal(), new Dog(), new Cat()};
		std::cout << std::endl;
		
		for (int i = 0; i < 3; i++) {
			std::cout << zoo[i]->getType() << std::endl;;
			zoo[i]->makeSound();
			std::cout << std::endl;
		}
		
		for (int i = 0; i < 3; i++) {
			delete zoo[i];
		}
	}
	std::cout << "\n******************************\n" << std::endl;
	{
		std::cout << "ARRAY OF ANIMAL:\n" << std::endl;
		
		/* For Dog/Cat a temporary object is created, then copied into the array using Animal::Animal(const Animal& src).
		   This only copies the Animal members, not the derived class members (object slicing) */

		Animal zoo[3] = {Animal(), Dog(), Cat()};
		std::cout << std::endl;
		
		for (int i = 0; i < 3; i++) {
			std::cout << zoo[i].getType() << std::endl;;
			zoo[i].makeSound();
			std::cout << std::endl;
		}
	}
}
