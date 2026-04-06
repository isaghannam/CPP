/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:17:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/06 17:59:53 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    
    if (argc < 2)
    {
        std::cerr << "Wrong number of args.\n";
        return 1;
    }
    PmergeMe pmergeme(argc, argv);
    
}