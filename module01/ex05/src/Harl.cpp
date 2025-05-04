#include "../inc/Harl.hpp"

std::string	Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

std::string	Harl::complaints[4] = {
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger.\nI really do!\n",
	"I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n",
	"I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n",
	"This is unacceptable! I want to speak to the manager now.\n"
};

Harl::Harl() {
	complainFuncPTR[0] = &Harl::debug;
	complainFuncPTR[1] = &Harl::info;
	complainFuncPTR[2] = &Harl::warning;
	complainFuncPTR[3] = &Harl::error;
}

Harl::~Harl() {}

void	Harl::complain(std::string input) {

	for (int i = 0; i < 4; i++) {
		if (this->levels[i] == input) {
			(this->*complainFuncPTR[i])();
			break ;
		}
	}
}

void	Harl::debug() {
	std::cout << "[ " + this->levels[0] + " ]\n" << this->complaints[0] << std::endl;
}

void	Harl::info() {
	std::cout << "[ " + this->levels[1] + " ]\n" << this->complaints[1] << std::endl;
}

void	Harl::warning() {
	std::cout << "[ " + this->levels[2] + " ]\n" << this->complaints[2] << std::endl;
}

void	Harl::error() {
	std::cout << "[ " + this->levels[3] + " ]\n" << this->complaints[3] << std::endl;
}
