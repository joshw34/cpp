#include "../inc/Harl.hpp"

int	find_level(std::string& level) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			return i;
	}
	return -1;
}

void	harlFilter(Harl& h, std::string& level) {
	int	hf = find_level(level);

	switch (hf) {
		case 0:
			h.complain("DEBUG");
		case 1:
			h.complain("INFO");
		case 2:
			h.complain("WARNING");
		case 3:
			h.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int	main(int ac, char** av) {
	Harl	h;
	std::string	level;

	if (ac != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return EXIT_FAILURE;
	}
	level = av[1];
	harlFilter(h, level);
	return EXIT_SUCCESS;
}
