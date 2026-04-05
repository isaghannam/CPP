/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:17:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/05 17:38:58 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    std::vector<std::string> input;
    if (argc < 2)
    {
        std::cerr << "Wrong number of args.\n";
        return 1;
    }
    for (int i = 1; i < argc; i++)
        input.push_back(argv[i]);
    PmergeMe pmergeme(input);
    
}