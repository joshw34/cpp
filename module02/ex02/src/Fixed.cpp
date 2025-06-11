#include "../inc/Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed() : fp_value(0) {
	//std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input) {
	//std::cout << "Int Constructor called" << std::endl;
	if (input > MAX_REP_VAL || input < MIN_REP_VAL) {
		std::cerr << RED << "Error value out of range for Fixed Point. Setting value to 0" << RESET << std::endl;
		this->fp_value = 0;
		return;
	}
	this->fp_value = input << this->frac;	
}

Fixed::Fixed(const float input) {
	//std::cout << "Float Constructor called" << std::endl;
	if (input > MAX_REP_VAL || input < MIN_REP_VAL) {
		std::cerr << RED << "Error value out of range for Fixed Point. Setting value to 0" << RESET << std::endl;
		this->fp_value = 0;
		return;
	}
	this->fp_value = static_cast<int>(roundf(input * (1 << this->frac)));
}

Fixed::Fixed(const Fixed& copy) {
	//std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(const int raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->fp_value = raw;
}

int Fixed::getRawBits() const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->fp_value;	
}

int Fixed::toInt() const {
	return this->fp_value >> this->frac;
}

float Fixed::toFloat() const {
	return static_cast<float>(this->fp_value) / (1 << this->frac);
}

Fixed& Fixed::operator=(const Fixed& src) {
	//std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &src)
		this->fp_value = src.getRawBits();
	return *this;
}

bool Fixed::operator<(const Fixed& comp) const {
	//std::cout << "< overload operator called" << std::endl;
	return this->getRawBits() < comp.getRawBits();
}

bool Fixed::operator>(const Fixed& comp) const {
	//std::cout << "> overload operator called" << std::endl;
	return this->getRawBits() > comp.getRawBits();
}

bool Fixed::operator<=(const Fixed& comp) const {
	//std::cout << "<= overload operator called" << std::endl;
	return this->getRawBits() <= comp.getRawBits();
}

bool Fixed::operator>=(const Fixed& comp) const {
	//std::cout << ">= overload operator called" << std::endl;
	return this->getRawBits() >= comp.getRawBits();
}

bool Fixed::operator==(const Fixed& comp) const {
	//std::cout << "== overload operator called" << std::endl;
	return this->getRawBits() == comp.getRawBits();
}

bool Fixed::operator!=(const Fixed& comp) const {
	//std::cout << "!= overload operator called" << std::endl;
	return this->getRawBits() != comp.getRawBits();
}

Fixed Fixed::operator+(const Fixed& add) const {
	double result = (this->toFloat() + add.toFloat());
	if (result < MIN_REP_VAL || result > MAX_REP_VAL) {
		std::cerr << RED << "Result out of range. Value unchanged" << RESET << std::endl;
		return *this;
	}
	Fixed	ret;
	ret.setRawBits(this->getRawBits() + add.getRawBits());
	return ret;
}

Fixed Fixed::operator-(const Fixed& sub) const {
	double result = (this->toFloat() - sub.toFloat());
	if (result < MIN_REP_VAL || result > MAX_REP_VAL) {
		std::cerr << RED << "Result out of range. Value unchanged" << RESET << std::endl;
		return *this;
	}
	Fixed	ret;
	ret.setRawBits(this->getRawBits() - sub.getRawBits());
	return ret;
}

Fixed Fixed::operator*(const Fixed& mult) const {
	double result = (this->toFloat() * mult.toFloat());
	if (result < MIN_REP_VAL || result > MAX_REP_VAL) {
		std::cerr << RED << "Result out of range. Value unchanged" << RESET << std::endl;
		return *this;
	}
	Fixed	ret;
	ret.setRawBits((this->getRawBits() * mult.getRawBits()) >> this->frac);
	return ret;
}

Fixed Fixed::operator/(const Fixed& div) const {
	if (div == 0) {
		std::cerr << RED << "\nError: division by 0 attempted. Value unchanged" << RESET << std::endl;
		return *this;
	}
	double result = (this->toFloat() / div.toFloat());
	if (result < MIN_REP_VAL || result > MAX_REP_VAL) {
		std::cerr << RED << "Result out of range. Value unchanged" << RESET << std::endl;
		return *this;
	}
	Fixed	ret;
	ret.setRawBits((this->getRawBits() << this->frac) / div.getRawBits());
	return ret;
}

Fixed& Fixed::operator++() {
	long result = this->fp_value + 1;
	if (result << 8 > MAX_REP_VAL) {
		std::cerr << RED << "Result out of range. Value unchanged" << RESET << std::endl;
		return *this;
	}
	this->fp_value += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	long result = this->fp_value + 1;
	if (result << 8 > MAX_REP_VAL) {
		std::cerr << RED << "Result out of range. Value unchanged" << RESET << std::endl;
		return *this;
	}
	Fixed	temp(*this);
	this->fp_value += 1;
	return temp;
}

Fixed& Fixed::operator--() {
	long result = this->fp_value - 1;
	if (result << 8 < MIN_REP_VAL) {
		std::cerr << RED << "Result out of range. Value unchanged" << RESET << std::endl;
		return *this;
	}
	this->fp_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	long result = this->fp_value - 1;
	if (result << 8 < MIN_REP_VAL) {
		std::cerr << RED << "Result out of range. Value unchanged" << RESET << std::endl;
		return *this;
	}
	Fixed	temp(*this);
	this->fp_value -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a <= b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a <= b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a >= b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a >= b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

