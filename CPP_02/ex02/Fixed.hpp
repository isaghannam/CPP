/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 08:11:34 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/10 15:32:57 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _FixedNumber;
        static const int _FracBits;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed(const int param);
        Fixed(const float param);
        Fixed& operator=(const Fixed& other);
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        static Fixed& min(Fixed& obj_one, Fixed& obj_two);
        static const Fixed& min(const Fixed& obj_one, const Fixed& obj_two);
        static Fixed& max(Fixed& obj_one, Fixed& obj_two);
        static const Fixed& max(const Fixed& obj_one, const Fixed& obj_two);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif