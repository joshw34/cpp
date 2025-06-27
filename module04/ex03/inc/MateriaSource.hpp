#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Colors.hpp" // IWYU pragma: keep
#include <string>

class MateriaSource : public IMateriaSource{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& src);

		void learnMateria(AMateria* m);
		AMateria* createMateria(const std::string& type);

	private:
		static const int maxMat = 4;
		AMateria* materia[maxMat];

		static void initMatArray(AMateria* materia[]);
		static void copyMatArray(AMateria* materia[], AMateria* const src[]);
		static void clearMatArray(AMateria* materia[]);
};

#endif
