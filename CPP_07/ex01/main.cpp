/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:32:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/27 16:41:23 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>


int main()
{
    {
        std::cout << "STRING ARRAY TEST\n";
        std::string str_array[3] = {"str1", "str2", "str3"};
        iter<std::string>(str_array, 3, print_item<std::string>);
    }

    {
        std::cout << "CONST STRING ARRAY TEST\n";
        std::string str_array[3] = {"str1", "str2", "str3"};
        iter<const std::string>(str_array, 3, print_const_item<std::string>);
    }
    {
        std::cout << "INT ARRAY TEST\n";
        int int_array[5] = {1,2,3,4,5};
        iter(int_array, 5, print_plus_one<int>);
    }
    return 0;
}
