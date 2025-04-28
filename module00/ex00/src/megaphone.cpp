#include <iostream>
#include <cctype>
#include <string>

int	main(int ac, char **av) {
	std::string	arg;

	if (ac > 1) {
		for (int i = 1; i < ac; i++) {
			arg = av[i];
			for (size_t j = 0; j != arg.length(); j++)
				std::cout << (char)std::toupper(arg[j]);
			if (i < ac - 1)
				std::cout << " ";
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
