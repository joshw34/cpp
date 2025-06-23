#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

#define SPACE std::cout << std::endl; 
#define WRITE std::cout <<
#define END << std::endl;

int main () {
	{
		/* Virtual keyword checks for object type at runtime and selects the relevant makeSound().
		   Virtual destructor ensures derived destructors are called even though we use a base class pointer */

		WRITE "TESTS FROM SUBJECT PDF:\n" END
		
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		SPACE

		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		SPACE
		
		meta->makeSound();
		j->makeSound();
		i->makeSound();
		SPACE
		
		delete i;
		delete j;
		delete meta;
	}
	WRITE "\n******************************\n" END	
	{
		/* Without the virtual keyword, these objects will use WrongAnimal::makeSound() even if they are WrongCat objects.
		   Without virtual destructor, only WrongAnimal::~WrongAnimal() is called, regardless of object type.
		   This is decided at compile time based on the pointer type not the object type pointer references */

		WRITE "TESTS FROM SUBJECT PDF (WRONGANIMAL / WRONGCAT):\n" END
		
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		
		std::cout << i->getType() << " " << std::endl;
		
		i->makeSound();
		meta->makeSound();
		
		delete i;
		delete meta;
	}
	WRITE "\n******************************\n" END	
	{
		/* Only one instance of Animal, Dog and Cat are created. An Animal pointer in the array then points to each.
		   This allows Dog/Cat member access via Animal pointer. */

		WRITE "ARRAY OF ANIMAL*:\n" END

		Animal* zoo[3] = {new Animal(), new Dog(), new Cat()};
		SPACE
		
		for (int i = 0; i < 3; i++) {
			WRITE zoo[i]->getType() END;
			zoo[i]->makeSound();
			SPACE
		}
		
		for (int i = 0; i < 3; i++) {
			delete zoo[i];
		}
	}
	SPACE WRITE "******************************" END SPACE	
	{
		WRITE "ARRAY OF ANIMAL:\n" END
		
		/* For Dog/Cat a temporary object is created, then copied into the array using Animal::Animal(const Animal& src).
		   This only copies the Animal members, not the derived class members (object slicing) */

		Animal zoo[3] = {Animal(), Dog(), Cat()};
		SPACE
		
		for (int i = 0; i < 3; i++) {
			WRITE zoo[i].getType() END;
			zoo[i].makeSound();
			SPACE
		}
	}
}
