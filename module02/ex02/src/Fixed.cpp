/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:24:46 by jwhitley          #+#    #+#             */
/*   Updated: 2025/06/12 12:24:24 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed() : fp_value(0) {
  // std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input) {
  // std::cout << "Int Constructor called" << std::endl;
  long check = static_cast<long>(input) << this->frac;
  if (!checkRange(check, 0))
    this->fp_value = 0;
  else
    this->fp_value = static_cast<int>(check);
}

Fixed::Fixed(const float input) {
  // std::cout << "Float Constructor called" << std::endl;
  long check = static_cast<long>(roundf(input * (1 << this->frac)));
  if (!checkRange(check, 0))
    this->fp_value = 0;
  else
    this->fp_value = static_cast<int>(check);
}

Fixed::Fixed(const Fixed& copy) : fp_value(copy.fp_value) {
  // std::cout << "Copy Constructor called" << std::endl;
}

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(const int raw) {
  // std::cout << "setRawBits member function called" << std::endl;
  this->fp_value = raw;
}

int Fixed::getRawBits() const {
  // std::cout << "getRawBits member function called" << std::endl;
  return this->fp_value;
}

long Fixed::getRawBitsLong() const {
  // std::cout << "getRawBitsLong member function called" << std::endl;
  return static_cast<long>(this->fp_value);
}

int Fixed::toInt() const {
  return this->fp_value >> this->frac;
}

float Fixed::toFloat() const {
  return static_cast<float>(this->fp_value) / (1 << this->frac);
}

Fixed& Fixed::operator=(const Fixed& src) {
  // std::cout << "Copy Assignment Operator called" << std::endl;
  if (this != &src)
    this->fp_value = src.getRawBits();
  return *this;
}

bool Fixed::operator<(const Fixed& comp) const {
  // std::cout << "< overload operator called" << std::endl;
  return this->getRawBits() < comp.getRawBits();
}

bool Fixed::operator>(const Fixed& comp) const {
  // std::cout << "> overload operator called" << std::endl;
  return this->getRawBits() > comp.getRawBits();
}

bool Fixed::operator<=(const Fixed& comp) const {
  // std::cout << "<= overload operator called" << std::endl;
  return this->getRawBits() <= comp.getRawBits();
}

bool Fixed::operator>=(const Fixed& comp) const {
  // std::cout << ">= overload operator called" << std::endl;
  return this->getRawBits() >= comp.getRawBits();
}

bool Fixed::operator==(const Fixed& comp) const {
  // std::cout << "== overload operator called" << std::endl;
  return this->getRawBits() == comp.getRawBits();
}

bool Fixed::operator!=(const Fixed& comp) const {
  // std::cout << "!= overload operator called" << std::endl;
  return this->getRawBits() != comp.getRawBits();
}

Fixed Fixed::operator+(const Fixed& add) const {
  long result = this->getRawBitsLong() + add.getRawBits();
  if (!checkRange(result, 2))
    return *this;
  Fixed ret;
  ret.setRawBits(static_cast<int>(result));
  return ret;
}

Fixed Fixed::operator-(const Fixed& sub) const {
  long result = this->getRawBitsLong() - sub.getRawBits();
  if (!checkRange(result, 2))
    return *this;
  Fixed ret;
  ret.setRawBits(static_cast<int>(result));
  return ret;
}

Fixed Fixed::operator*(const Fixed& mult) const {
  long result = (this->getRawBitsLong() * mult.getRawBits()) >> this->frac;
  if (!checkRange(result, 2))
    return *this;
  Fixed ret;
  ret.setRawBits(static_cast<int>(result));
  return ret;
}

Fixed Fixed::operator/(const Fixed& div) const {
  if (div == 0) {
    error_print(1);
    return *this;
  }
  long result = (this->getRawBitsLong() << this->frac) / div.getRawBits();
  if (!checkRange(result, 2))
    return *this;
  Fixed ret;
  ret.setRawBits(static_cast<int>(result));
  return ret;
}

Fixed& Fixed::operator++() {
  if (!checkRange(this->fp_value, '+'))
    return *this;
  this->fp_value += 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  if (!checkRange(this->fp_value, '+'))
    return *this;
  Fixed temp(*this);
  this->fp_value += 1;
  return temp;
}

Fixed& Fixed::operator--() {
  if (!checkRange(this->fp_value, '-'))
    return *this;
  this->fp_value -= 1;
  return *this;
}

Fixed Fixed::operator--(int) {
  if (!checkRange(this->fp_value, '-'))
    return *this;
  Fixed temp(*this);
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

bool Fixed::checkRange(const long& n, const int& type) {
  if (n < INT_MIN || n > INT_MAX) {
    error_print(type);
    return false;
  }
  return true;
}

bool Fixed::checkRange(const int& n, const char& sign) {
  if ((sign == '+' && n >= INT_MAX) || (sign == '-' && n <= INT_MIN)) {
    error_print(2);
    return false;
  }
  return true;
}

void Fixed::error_print(const int& error_num) {
  std::string errors[3];

  errors[0] = "Error: value out of range for Fixed Point. Setting value to 0";
  errors[1] = "\nError: division by 0 attempted. Value unchanged";
  errors[2] = "Error: Result out of range. Value unchanged";

  std::cerr << RED << errors[error_num] << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
