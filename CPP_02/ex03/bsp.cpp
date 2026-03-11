/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:19:42 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/11 10:04:46 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed c1;
	Fixed c2;
	Fixed c3;
	Point ab = b - a;
	Point bc = c - b;
	Point ca = a - c;
	Point ap = point - a;
	Point bp = point - b;
	Point cp = point - c;

	c1 = ab.cross_prod(ap);
	c2 = bc.cross_prod(bp);
	c3 = ca.cross_prod(cp);
	if ((c1 > Fixed(0) && c2 > Fixed(0) && c3 > Fixed(0)) || (c1 < Fixed(0)
			&& c2 < Fixed(0) && c3 < Fixed(0)))
    {
		return (true);
    }
	return (false);
}