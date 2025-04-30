#include <iostream>
#include <string>

int	main(void) {
	std::string		s = "HI THIS IS BRAIN";
	std::string*	stringPTR = &s;
	std::string&	stringREF = s;

	std::cout	<< "Str Address: " << &s << "\n"
				<< "Ptr Address: " << stringPTR << "\n"
				<< "Ref Address: " << &stringREF << "\n\n"
				<< "Str Value: " << s << "\n"
				<< "Ptr Value: " << *stringPTR << "\n"
				<< "Ref Value: " << stringREF << std::endl;
}
