#include "../inc/Fixed.hpp"
#include <iomanip>

#define GREEN "\033[32m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

int main() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << GREEN << "Tests from subject pdf:" << RESET << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::boolalpha;

	std::cout << GREEN << "\nArithmetic Operators:" << RESET << std::endl;
	Fixed c(10);
	Fixed d(8.8f);
	Fixed e(132);
	Fixed f(4);
	Fixed g(13.0f);
	std::cout << c << " * " << d << " = " << c * d << std::endl;
	std::cout << c * d << " + " << e << " = " << (c * d) + e << std::endl;
	std::cout << (c * d) + e << " / " << f << " = " << ((c * d) + e) / f << std::endl;
	std::cout << ((c * d) + e) / f << " - " << g << " = " << (((c * d) + e ) / f) - g  << std::endl;


	std::cout << GREEN << "\nComparison Operators:" << RESET << std::endl;
	Fixed low = 100;
	Fixed low_copy = low;
	Fixed high = low;
	high++;

	bool result = low < high; 
	std::cout << low << " < " << high << " = " << result << std::endl;
	result = low > high; 
	std::cout << low << " > " << high << " = " << result << std::endl;
	result = low <= high; 
	std::cout << low << " <= " << high << " = " << result << std::endl;
	result = low >= high; 
	std::cout << low << " >= " << high << " = " << result << std::endl;
	result = low <= low_copy;
	std::cout << low << " <= " << low_copy << " = " << result << std::endl;
	result = low >= low_copy;
	std::cout << low << " >= " << low_copy << " = " << result << std::endl;
	result = low == high; 
	std::cout << low << " == " << high << " = " << result << std::endl;
	result = low == low_copy;
	std::cout << low << " == " << low_copy << " = " << result << std::endl;
	result = low != high; 
	std::cout << low << " != " << high << " = " << result << std::endl;
	result = low != low_copy;
	std::cout << low << " != " << low_copy << " = " << result << std::endl;


	std::cout << GREEN << "\nIncrement / Decrement Operators:" << RESET << std::endl;
	Fixed j;
	std::cout << "j = " << j << std::endl; 
	std::cout << "\n++j = " << ++j << std::endl;
	std::cout << "\n--j = " << --j << std::endl;
	std::cout << "\nj++ = " << j++ << "\nj = " << j << std::endl;
	std::cout << "\nj-- = " << j-- << "\nj = " << j << std::endl;


	std::cout << GREEN << "\nMin / Max:" << RESET << std::endl;
	std::cout << "Max(" << low << ", " << high << ") = " << Fixed::max(low, high) << std::endl;
	std::cout << "Min(" << low << ", " << high << ") = " << Fixed::min(low, high) << std::endl;


	std::cout << GREEN << "\nError Handling:" << RESET << std::endl;
	Fixed max_fix;
	max_fix.setRawBits(INT_MAX);
	Fixed min_fix;
	min_fix.setRawBits(INT_MIN);
	Fixed ten(10);
	Fixed zero;

	std::cout << "Division by zero:\n"
	          << ten << " / " << zero << " = " << ten / zero << std::endl;

	std::cout << "\nConstructor Overflow:\n"
		      << Fixed(INT_MAX) << std::endl;
	std::cout << "\nConstructor Underflow:\n"
		      << Fixed(INT_MIN) << std::endl;

	std::cout << std::fixed << std::setprecision(0);

	std::cout << "\nAddition Overflow:\n"
		      << max_fix << " + 20\n" << max_fix + 20 << std::endl;
	std::cout << "\nAddition Underflow:\n"
		      << min_fix << " + -20\n" << min_fix + -20 << std::endl;

	std::cout << "\nSubtraction Overflow:\n"
		      << max_fix << " - -20\n" << max_fix - -20 << std::endl;
	std::cout << "\nSubtraction Underflow:\n"
		      << min_fix << " - 20\n" << min_fix - 20 << std::endl;

	std::cout << "\nMultiplication Overflow:\n"
		      << max_fix << " * 2\n" << max_fix * 2 << std::endl;
	std::cout << "\nMultiplication Underflow:\n"
		      << min_fix << " * 2\n" << min_fix * 2 << std::endl;
	
	std::cout << "\nDivision Overflow:\n"
		      << max_fix << " / 0.5\n" << max_fix / 0.5f << std::endl;
	std::cout << "\nDivision Underflow:\n"
		      << min_fix << " / 0.5\n" << min_fix / 0.5f << std::endl;

	std::cout << "\nPre-Increment Overflow:\n"
		      << "++" << max_fix << "\n" << ++max_fix << std::endl;
	std::cout << "\nPost-Increment Overflow:\n"
		      << max_fix << "++\n" << max_fix++ << std::endl;

	std::cout << "\nPre-Decrement Underflow:\n"
		      << "--" << min_fix << "\n" << --min_fix << std::endl;
	std::cout << "\nPost-Decrement Underflow:\n"
		      << min_fix << "--\n" << min_fix-- << std::endl;

	return 0;
}
