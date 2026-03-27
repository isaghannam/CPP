/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:18:29 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/27 15:43:53 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> list_int;
    list_int.push_back(1);
    list_int.push_back(2);
    list_int.push_back(3);
    try
    {
        std::cout << *::easyfind(list_int, 2) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << *::easyfind(list_int, 0) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::vector<int> vector_int;
    vector_int.push_back(1);
    vector_int.push_back(2);
    vector_int.push_back(3);
    try
    {
        std::cout << *::easyfind(vector_int, 2) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << *::easyfind(vector_int, 0) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}