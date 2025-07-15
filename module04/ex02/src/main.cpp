#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

Dog* dog_cast(Animal* src) {
	return dynamic_cast<Dog*>(src);
}

Cat* cat_cast(Animal* src) {
	return dynamic_cast<Cat*>(src);
}

int main () {
	{
		std::cout << "TESTS FROM SUBJECT PDF:\n" << std::endl;

		const Animal* j = new Dog;
		const Animal* i = new Cat;
		std::cout << std::endl;

		
		delete j;
		delete i;
		std::cout << std::endl;
	}
	std::cout << "\n****************************************\n" << std::endl;
	{
		std::cout << "\nCREATE ARRAY[6] (3xCAT and 3xDOG)\n" << std::endl;

		Animal* zoo[6];

		for(int i = 0; i < 6; i++) {
			if (i < 3)
				zoo[i] = new Cat;
			else
				zoo[i] = new Dog;
			zoo[i]->makeSound();
			std::cout << std::endl;
		}

		std::cout << "\nSET THOUGHTS:\n" << std::endl;
		cat_cast(zoo[0])->setIdea(0, "Meow");
		cat_cast(zoo[1])->setIdea(0, "I'm Hungry");
		cat_cast(zoo[2])->setIdea(0, "Yawn");
		dog_cast(zoo[3])->setIdea(0, "Woof");
		dog_cast(zoo[4])->setIdea(0, "Squirrel!");
		dog_cast(zoo[5])->setIdea(0, "zzzzzzzz");
		cat_cast(zoo[0])->printIdea(0);
		cat_cast(zoo[1])->printIdea(0);
		cat_cast(zoo[2])->printIdea(0);
		dog_cast(zoo[3])->printIdea(0);
		dog_cast(zoo[4])->printIdea(0);
		dog_cast(zoo[5])->printIdea(0);
		std::cout << std::endl;

		std::cout << "\nSET CATS/DOGS 2 & 3 = CAT/DOG 1\n" << std::endl;
		*cat_cast(zoo[1]) = *cat_cast(zoo[0]);
		*cat_cast(zoo[2]) = *cat_cast(zoo[0]);
		*dog_cast(zoo[4]) = *dog_cast(zoo[3]);
		*dog_cast(zoo[5]) = *dog_cast(zoo[3]);

		cat_cast(zoo[0])->printIdea(0);
		cat_cast(zoo[1])->printIdea(0);
		cat_cast(zoo[2])->printIdea(0);
		dog_cast(zoo[3])->printIdea(0);
		dog_cast(zoo[4])->printIdea(0);
		dog_cast(zoo[5])->printIdea(0);
		std::cout << std::endl;

		std::cout << "\nDEEP COPY TEST:\n" << std::endl;
		cat_cast(zoo[0])->setIdea(0, "Meow");
		cat_cast(zoo[1])->setIdea(0, "I'm Hungry");
		cat_cast(zoo[2])->setIdea(0, "Yawn");
		dog_cast(zoo[3])->setIdea(0, "Woof");
		dog_cast(zoo[4])->setIdea(0, "Squirrel!");
		dog_cast(zoo[5])->setIdea(0, "zzzzzzzz");
		cat_cast(zoo[0])->printIdea(0);
		cat_cast(zoo[1])->printIdea(0);
		cat_cast(zoo[2])->printIdea(0);
		dog_cast(zoo[3])->printIdea(0);
		dog_cast(zoo[4])->printIdea(0);
		dog_cast(zoo[5])->printIdea(0);
		std::cout << std::endl;

		std::cout << "\nDESTROY ARRAY USING VIRTUAL BASE DESTRUCTOR:\n" << std::endl;

		for(int i = 0; i < 6; i++) {
			delete zoo[i];
			std::cout << std::endl;
		}
	}
	return 0;
}
