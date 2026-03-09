/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:11:18 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/09 09:20:35 by ighannam         ###   ########.fr       */
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

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy contructor called\n";
    *this=other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_FixedNumber = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return (this->_FixedNumber);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called\n";
    this->_FixedNumber = raw;
}