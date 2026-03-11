/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:11:18 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/10 14:29:41 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_FracBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->_FixedNumber = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy contructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->_FixedNumber = other._FixedNumber;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_FixedNumber);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_FixedNumber = raw;
}

Fixed::Fixed(const int param)
{
	std::cout << "Int constructor called\n";
	this->_FixedNumber = param << _FracBits;
}

Fixed::Fixed(const float param)
{
	std::cout << "Float constructor called\n";
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
