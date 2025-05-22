#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> // IWYU pragma: keep
#include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& copy);
		~Fixed();

		void	setRawBits(const int raw);
		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;

		Fixed& operator=(const Fixed& src);

	private:
  		int fp_value;
  		static const int frac;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif
