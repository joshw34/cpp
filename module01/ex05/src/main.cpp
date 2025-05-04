#include "../inc/Harl.hpp"

int	main(void) {
	Harl	h;
	std::string	level;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++) {
		h.complain(levels[i]);
		std::cout << "\n";
	}
	while (level.compare("EXIT") != 0) {
		std::cout << "\nEnter: DEBUG, INFO, WARNING, ERROR or EXIT\n> ";
		std::getline(std::cin, level);
		h.complain(level);
	}
}
