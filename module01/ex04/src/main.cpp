#include "../inc/StrReplace.hpp"
#include <cstdlib>

int main(int ac, char** av) {
	StrReplace	replacer;

	if (ac != 4) {
		std::cerr << "Error: Incorrect number of arguments provided" << std::endl;
		return EXIT_FAILURE;
	}
	if (!replacer.setInfile(av[1]))
		return EXIT_FAILURE;
	if (!replacer.setStrings(av[2], av[3]))
		return EXIT_FAILURE;
	replacer.replace();
	return EXIT_SUCCESS;
}
