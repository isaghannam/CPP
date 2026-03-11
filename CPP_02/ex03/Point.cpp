/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:10:58 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/11 10:10:45 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
    : x(Fixed(0)), y(Fixed(0))
{
}

Point::~Point()
{
    
}

Point::Point(const Point& other)
    : x(other.x), y(other.y)
{
}

Point& Point::operator=(const Point& other)
{
    (void)other;
    return (*this);
}

Point::Point(const float x, const float y)
    : x(Fixed(x)), y(Fixed(y))
{
    
}

Point::Point(Fixed const x, Fixed const y)
    : x(x), y(y)
{
    
}

Fixed Point::cross_prod(const Point& other) const
{
    return ((this->x * other.y) - (this->y * other.x));
}

Point Point::operator-(const Point& other) const
{
    Point result(this->x - other.x, this->y - other.y);
    return (result);
}

bool Point::operator==(const Point& other) const
{
    if (this->x == other.x && this->y == other.y)
        return (true);
    return (false);
}