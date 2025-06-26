#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

#define SPACE std::cout << std::endl; 
#define WRITE std::cout <<
#define END << std::endl;

Dog* dog_cast(Animal* src) {
	return dynamic_cast<Dog*>(src);
}

Cat* cat_cast(Animal* src) {
	return dynamic_cast<Cat*>(src);
}

int main () {
	/*{
		WRITE "TESTS FROM SUBJECT PDF:\n" END

		const Animal* j = new Dog;
		const Animal* i = new Cat;
		SPACE

		
		delete j;
		delete i;
		SPACE
	}
	WRITE "\n****************************************\n" END
	{
		WRITE "\nCREATE ARRAY[6] (3xCAT and 3xDOG)\n" END

		Animal* zoo[6];

		for(int i = 0; i < 6; i++) {
			if (i < 3)
				zoo[i] = new Cat;
			else
				zoo[i] = new Dog;
			zoo[i]->makeSound();
			SPACE
		}


		WRITE "\nSET THOUGHTS:\n" END
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
		SPACE

		WRITE "\nSET CATS/DOGS 2 & 3 = CAT/DOG 1\n" END
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
		SPACE

		WRITE "\nDEEP COPY TEST:\n" END
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
		SPACE

		WRITE "\nDESTROY ARRAY USING VIRTUAL BASE DESTRUCTOR:\n" END

		for(int i = 0; i < 6; i++) {
			delete zoo[i];
			SPACE
		}
	}*/
	Dog dave;
	return 0;
}
