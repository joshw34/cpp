#include <iostream>
#include <cctype>
#include <string>

void printUppercase(int ac, char **av) {
	std::string	arg;

    for (int i = 1; i < ac; i++) {
	    arg = av[i];

        for (size_t j = 0; j < arg.length(); j++)
            std::cout << (char)std::toupper(arg[j]);
        
        if (i < ac - 1)
            std::cout << " ";
    }
}

int	main(int ac, char **av) {
	if (ac > 1) 
        printUppercase(ac, av);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
