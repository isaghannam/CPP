/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:32:44 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/26 17:54:44 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter(T * array, const size_t size, F function)
{
    for (size_t i = 0; i < size; i++)
        function(array[i]);
}

template<typename T>
void print_item(T & item)
{
    std::cout << item << " \n";
}

template<typename T>
void print_const_item(T const & item)
{
    std::cout << item << "\n";
}

template<typename T>
void print_plus_one(T & item)
{
    std::cout << ++item << "\n";
}

#endif