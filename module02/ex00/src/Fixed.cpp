#include "../inc/Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed() : fp_value(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(Fixed& copy) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &src)
		this->fp_value = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fp_value;	
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fp_value = raw;
}


