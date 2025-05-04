#include "../inc/Harl.hpp"

void	harlFilter(Harl& h, std::string& input) {
	int	hf = -1;

	for (int i = 0; i < 4; i++) {
		if (h.levels[i] == input) {
			hf = i;
			break ;
		}
	}
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
	std::string	input;

	if (ac != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return EXIT_FAILURE;
	}
	input = av[1];
	harlFilter(h, input);
	return EXIT_SUCCESS;
}
