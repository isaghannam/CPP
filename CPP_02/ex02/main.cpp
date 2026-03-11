/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:14:01 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/11 10:24:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    // Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << std::boolalpha;

    std::cout << "\n===== CONSTRUCTORS =====\n";

    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a: " << a << " (expected: 0)\n";
    std::cout << "b: " << b << " (expected: 10)\n";
    std::cout << "c: " << c << " (expected approx: 42.42)\n";
    std::cout << "d (copy of b): " << d << " (expected: 10)\n";


    std::cout << "\n===== ASSIGNMENT =====\n";

    a = Fixed(5.5f);
    std::cout << "a after assignment: " << a << " (expected: 5.5)\n";


    std::cout << "\n===== COMPARISON OPERATORS =====\n";

    Fixed x(5);
    Fixed y(3);

    std::cout << "x: " << x << " y: " << y << "\n";

    std::cout << "x > y: " << (x > y) << " (expected: true)\n";
    std::cout << "x < y: " << (x < y) << " (expected: false)\n";
    std::cout << "x >= y: " << (x >= y) << " (expected: true)\n";
    std::cout << "x <= y: " << (x <= y) << " (expected: false)\n";
    std::cout << "x == y: " << (x == y) << " (expected: false)\n";
    std::cout << "x != y: " << (x != y) << " (expected: true)\n";


    std::cout << "\n===== ARITHMETIC OPERATORS =====\n";

    Fixed m(5.5f);
    Fixed n(2);

    std::cout << "m: " << m << " n: " << n << "\n";

    std::cout << "m + n = " << (m + n) << " (expected: 7.5)\n";
    std::cout << "m - n = " << (m - n) << " (expected: 3.5)\n";
    std::cout << "m * n = " << (m * n) << " (expected: 11)\n";
    std::cout << "m / n = " << (m / n) << " (expected: 2.75)\n";


    std::cout << "\n===== INCREMENT / DECREMENT =====\n";

    Fixed inc(3);

    std::cout << "inc: " << inc << " (expected: 3)\n";

    std::cout << "++inc: " << ++inc << " (expected: 3.0039 approx)\n";
    std::cout << "inc after ++: " << inc << " (expected: same as above)\n";

    std::cout << "inc++: " << inc++ << " (expected: previous value)\n";
    std::cout << "inc after inc++: " << inc << " (expected: slightly bigger)\n";

    std::cout << "--inc: " << --inc << " (expected: slightly smaller)\n";
    std::cout << "inc after --: " << inc << "\n";

    std::cout << "inc--: " << inc-- << "\n";
    std::cout << "inc after inc--: " << inc << "\n";


    std::cout << "\n===== MIN / MAX =====\n";

    Fixed p(8);
    Fixed q(12);

    std::cout << "p: " << p << " q: " << q << "\n";

    std::cout << "min(p, q): " << Fixed::min(p, q) << " (expected: 8)\n";
    std::cout << "max(p, q): " << Fixed::max(p, q) << " (expected: 12)\n";

    const Fixed r(1.5f);
    const Fixed s(2.5f);

    std::cout << "min(r, s): " << Fixed::min(r, s) << " (expected: 1.5)\n";
    std::cout << "max(r, s): " << Fixed::max(r, s) << " (expected: 2.5)\n";


    std::cout << "\n===== TO INT / TO FLOAT =====\n";

    Fixed t(42.42f);

    std::cout << "t: " << t << " (expected approx: 42.42)\n";
    std::cout << "t.toInt(): " << t.toInt() << " (expected: 42)\n";
    std::cout << "t.toFloat(): " << t.toFloat() << " (expected approx: 42.42)\n";

    std::cout << "\n===== END TEST =====\n";

    return 0;
}