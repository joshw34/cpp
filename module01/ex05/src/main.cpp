#include "../inc/Harl.hpp"

int	main(void) {
	Harl	h;
	std::string	input;
	
	for (int i = 0; i < 4; i++) {
		h.complain(h.levels[i]);
	}
	while (input.compare("EXIT") != 0) {
		std::cout << "Enter: DEBUG, INFO, WARNING, ERROR or EXIT\n> ";
		std::getline(std::cin, input);
		h.complain(input);
	}
}
