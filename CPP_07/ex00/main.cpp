/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:08:06 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/26 14:19:40 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "INT TEST a = 1  b = 2\n";
        int a = 1;
        int b = 2;
        std::cout << "a = " << a << "  b = " << b << std::endl;
        std::cout << "SWAP TEST\n";
        ::swap<int>(a, b);
        std::cout << "a = " << a << "  b = " << b << std::endl;
        std::cout << "MIN TEST\n";
        std::cout << "MIN = " << ::min<int>(a, b) << std::endl;
        std::cout << "MAX TEST\n";
        std::cout << "MAX = " << ::max<int>(a, b) << std::endl;
    }

    {
        std::cout << "\nFLOAT TEST a = 10.3  b = -2.5\n";
        float a = 10.3;
        float b = -2.5;
        std::cout << "a = " << a << "  b = " << b << std::endl;
        std::cout << "SWAP TEST\n";
        ::swap<float>(a, b);
        std::cout << "a = " << a << "  b = " << b << std::endl;
        std::cout << "MIN TEST\n";
        std::cout << "MIN = " << ::min<float>(a, b) << std::endl;
        std::cout << "MAX TEST\n";
        std::cout << "MAX = " << ::max<float>(a, b) << std::endl;
    }

    {
        std::cout << "\nSTRING TEST a = STR1  b = STR2\n";
        std::string a = "STR1";
        std::string b = "STR2";
        std::cout << "a = " << a << "  b = " << b << std::endl;
        std::cout << "SWAP TEST\n";
        ::swap<std::string>(a, b);
        std::cout << "a = " << a << "  b = " << b << std::endl;
        std::cout << "MIN TEST\n";
        std::cout << "MIN = " << ::min<std::string>(a, b) << std::endl;
        std::cout << "MAX TEST\n";
        std::cout << "MAX = " << ::max<std::string>(a, b) << std::endl;
    }

    {
        std::cout << "\nSUBJECT TEST\n";
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    
    return 0;
}