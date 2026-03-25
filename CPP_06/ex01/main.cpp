/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:29:59 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/25 17:01:09 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    Data *data_ptr = &data;
    std::cout << "data_ptr: " << data_ptr << std::endl;
    uintptr_t int_ptr = Serializer::serialize(data_ptr);
    std::cout << "int_prt: " << int_ptr << std::endl;
    data_ptr = Serializer::deserialize(int_ptr);
    std::cout << "data_ptr: " << data_ptr << std::endl;

    if (data_ptr == &data)
        std::cout << "OK: pointers match" << std::endl;
    else
        std::cout << "ERROR: pointers differ" << std::endl;
    return (0);
}