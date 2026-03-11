/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:15:03 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/11 10:06:53 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{

    {
        
        Point a(0,0);
        Point b(10,0);
        Point p(2,2);
    
        Point ab = b - a;
        Point ap = p - a;
    
        std::cout << ab.cross_prod(ap) << std::endl;
    }
    
	{
		Point a;
		Point b(Fixed(10), Fixed(0));
		Point c(Fixed(0), Fixed(10));
		Point p(Fixed(2), Fixed(2));
		std::cout << "Inside point (expected true). Result: " << std::boolalpha << bsp(a,
			b, c, p) << std::endl;
	}

	{
		Point a;
		Point b(Fixed(10), Fixed(0));
		Point c(Fixed(0), Fixed(10));
		Point p(Fixed(3), Fixed(1));
		std::cout << "Inside point (expected true). Result: " << std::boolalpha << bsp(a,
			b, c, p) << std::endl;
	}

	{
		Point a;
		Point b(Fixed(10), Fixed(0));
		Point c(Fixed(0), Fixed(10));
		Point p(Fixed(1), Fixed(3));
		std::cout << "Inside point (expected true). Result: " << std::boolalpha << bsp(a,
			b, c, p) << std::endl;
	}

	{
		Point a;
		Point b(Fixed(10), Fixed(0));
		Point c(Fixed(0), Fixed(10));
		Point p(Fixed(0), Fixed(0));
		std::cout << "Point is vertex (expected false). Result: " << std::boolalpha << bsp(a,
			b, c, p) << std::endl;
	}

	{
		Point a;
		Point b(Fixed(10), Fixed(0));
		Point c(Fixed(0), Fixed(10));
		Point p(Fixed(10), Fixed(0));
		std::cout << "Point is vertex (expected false). Result: " << std::boolalpha << bsp(a,
			b, c, p) << std::endl;
	}

	{
		Point a;
		Point b(Fixed(10), Fixed(0));
		Point c(Fixed(0), Fixed(10));
		Point p(Fixed(10), Fixed(10));
		std::cout << "Outside point (expected false). Result: " << std::boolalpha << bsp(a,
			b, c, p) << std::endl;
	}

	{
		Point a;
		Point b(Fixed(10), Fixed(0));
		Point c(Fixed(0), Fixed(10));
		Point p(Fixed(-1), Fixed(1));
		std::cout << "Outside point (expected false). Result: " << std::boolalpha << bsp(a,
			b, c, p) << std::endl;
	}

	{
		Point a;
		Point b(Fixed(10), Fixed(0));
		Point c(Fixed(0), Fixed(10));
		Point p(Fixed(6), Fixed(6));
		std::cout << "Outside point (expected false). Result: " << std::boolalpha << bsp(a,
			b, c, p) << std::endl;
	}

	{
		Point a;
		Point b(Fixed(10), Fixed(0));
		Point c(Fixed(0), Fixed(10));
		Point p(Fixed(5), Fixed(5));
		std::cout << "Edge point (expected false). Result: " << std::boolalpha << bsp(a,
			b, c, p) << std::endl;
	}

	{
		Point a(Fixed(0), Fixed(0));
		Point b(Fixed(10), Fixed(0));
		Point c(Fixed(0), Fixed(10));
		Point p(Fixed(0), Fixed(5));

		std::cout << "Edge vertical (expected false): " << std::boolalpha << bsp(a,
			b, c, p) << std::endl;
	}

	return (0);
}