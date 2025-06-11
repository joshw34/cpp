#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> // IWYU pragma: keep
#include <climits>
#include <cmath>

#define RED "\033[31m"
#define RESET "\033[0m"
#define MAX_REP_VAL 8388607 
#define MIN_REP_VAL -8388608 

class Fixed {
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& copy);
		~Fixed();

		void setRawBits(const int raw);
		int getRawBits(void) const;
		int toInt(void) const;
		float toFloat(void) const;

		Fixed& operator=(const Fixed& src);

		bool operator<(const Fixed& comp) const;
		bool operator>(const Fixed& comp) const;
		bool operator<=(const Fixed& comp) const;
		bool operator>=(const Fixed& comp) const;
		bool operator==(const Fixed& comp) const;
		bool operator!=(const Fixed& comp) const;

		Fixed operator+(const Fixed& add) const;
		Fixed operator-(const Fixed& sub) const;
		Fixed operator*(const Fixed& mult) const;
		Fixed operator/(const Fixed& div) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

	private:
  		int fp_value;
  		static const int frac;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
