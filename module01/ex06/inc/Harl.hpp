#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream> // IWYU pragma: keep

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
};

#endif
