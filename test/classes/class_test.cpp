#include "./class_test.hpp"

int	main(void)
{
	std::string name;
	std::cout << "Enter Name;" << std::endl;
	std::getline(std::cin, name);
	MyClass	josh(name);
	std::cout << josh.name << josh.name.length() <<std::endl;
	return (0);
}
