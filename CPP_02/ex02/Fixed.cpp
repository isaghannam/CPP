/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:11:18 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/11 10:19:42 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_FracBits = 8;

Fixed::Fixed()
{
	this->_FixedNumber = 0;
}

Fixed::~Fixed()
{
	
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_FixedNumber = other._FixedNumber;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_FixedNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->_FixedNumber = raw;
}

Fixed::Fixed(const int param)
{
	this->_FixedNumber = param << _FracBits;
}

Fixed::Fixed(const float param)
{
	this->_FixedNumber = (int)(roundf(param * (1 << _FracBits)));
}

float Fixed::toFloat(void) const
{
	return ((float)(_FixedNumber / (float)(1 <<_FracBits)));
}

int Fixed::toInt(void) const
{
	return ((int)(roundf((float)(_FixedNumber >> _FracBits))));
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed& other) const
{
	if (this->_FixedNumber > other._FixedNumber)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& other) const
{
	if (this->_FixedNumber < other._FixedNumber)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& other) const
{
	if (this->_FixedNumber >= other._FixedNumber)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& other) const
{
	if (this->_FixedNumber <= other._FixedNumber)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& other) const
{
	if (this->_FixedNumber == other._FixedNumber)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& other) const
{
	if (this->_FixedNumber != other._FixedNumber)
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_FixedNumber + other._FixedNumber);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_FixedNumber - other._FixedNumber);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result = Fixed(this->toFloat() * other.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result = Fixed(this->toFloat() / other.toFloat());
	return (result);
}

Fixed& Fixed::operator++(void)
{
	this->_FixedNumber++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_FixedNumber++;
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	this->_FixedNumber--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_FixedNumber--;
	return (temp);
}

Fixed& Fixed::min(Fixed& obj_one, Fixed& obj_two)
{
	if (obj_one >= obj_two)
		return (obj_two);
	return (obj_one);
}

const Fixed& Fixed::min(const Fixed& obj_one, const Fixed& obj_two)
{
	if (obj_one >= obj_two)
		return (obj_two);
	return (obj_one);
}

Fixed& Fixed::max(Fixed& obj_one, Fixed& obj_two)
{
	if (obj_one <= obj_two)
		return (obj_two);
	return (obj_one);
}

const Fixed& Fixed::max(const Fixed& obj_one, const Fixed& obj_two)
{
	if (obj_one <= obj_two)
		return (obj_two);
	return (obj_one);
}
