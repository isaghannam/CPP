/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:11:11 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/11 10:02:35 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;
public:
    Point();
    ~Point();
    Point(const Point& other);
    Point& operator=(const Point& other);
    Point(const float x, const float y);
    Point(Fixed const x, Fixed const y);
    Fixed cross_prod(const Point& other) const;
    Point operator-(const Point& other) const;
    bool operator==(const Point& other) const;
};


#endif