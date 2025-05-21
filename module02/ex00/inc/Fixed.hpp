#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> // IWYU pragma: keep

class Fixed {
	public:
		Fixed();
		Fixed(Fixed& copy);
		~Fixed();

		Fixed& operator=(const Fixed& src);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
  		int fp_value;
  		static const int frac;
};

#endif
