#ifndef CLASS_TEST_HPP
#define CLASS_TEST_HPP

#include <string>
#include <iostream>

class MyClass{
	public:
		MyClass(std::string name) : index(0), name(name) {}
		int	index;
		std::string	name;
};

#endif
