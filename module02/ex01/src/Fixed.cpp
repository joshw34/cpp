#include "../inc/Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed() : fp_value(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input) {
	std::cout << "Int Constructor called" << std::endl;
	this->fp_value = input << this->frac;	
}

Fixed::Fixed(const float input) {
	std::cout << "Float Constructor called" << std::endl;
	this->fp_value = static_cast<int>(roundf(input * (1 << this->frac)));
}

Fixed::Fixed(const Fixed& copy) : fp_value(copy.fp_value) {
	std::cout << "Copy Constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(const int raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->fp_value = raw;
}

int	Fixed::getRawBits() const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->fp_value;	
}

int	Fixed::toInt() const {
	return this->fp_value >> this->frac;
}

float	Fixed::toFloat() const {
	return static_cast<float>(this->fp_value) / (1 << this->frac);
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &src)
		this->fp_value = src.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

