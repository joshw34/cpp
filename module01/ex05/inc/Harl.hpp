#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream> // IWYU pragma: keep
#include <cstdlib>	// IWYU pragma: keep

class	Harl {
	public:
		Harl();
		~Harl();
		void	complain(std::string input);
		static	std::string	levels[4];

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		static	std::string	complaints[4];
		void (Harl::*complainFuncPTR[4])(void);
};

#endif
