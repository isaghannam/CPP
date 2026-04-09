/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:17:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/09 11:52:45 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	double time_vec;
	double time_deq;
	if (argc < 2)
	{
		std::cerr << "Wrong number of args.\n";
		return (1);
	}
    try
    {
        PmergeMe pmergeme(argc, argv);
        time_vec = pmergeme.PmergeMeSortVec();
        time_deq = pmergeme.PmergeMeSortDeq();
        std::cout << pmergeme;
        std::cout << "Time to process a range of " << pmergeme.getInput().size() 
            << " elements with std::vector : " << time_vec << " us" << std::endl;
        std::cout << "Time to process a range of " << pmergeme.getInput().size() 
            << " elements with std::deque  : " << time_deq << " us" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	return (0);
}
