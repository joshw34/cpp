#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream> // IWYU pragma: keep

#define RED "\033[31m"
#define YELLOW  "\033[33m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

class Brain {
	public:
		Brain();
		Brain(const Brain& src);
		~Brain();

		Brain& operator=(const Brain& src);
		
		const std::string& getIdea(int index) const;
		void printIdea(int index, const std::string& type) const;
		void setIdea(int index, const std::string& newIdea);

	private:
		static const int brainSize = 100;
		std::string ideas[brainSize];
};

#endif
