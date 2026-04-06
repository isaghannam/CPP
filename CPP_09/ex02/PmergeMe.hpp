/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:17:01 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/06 18:06:22 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

class PmergeMe
{
private:
    PmergeMe();
    std::vector<int> input;
    std::vector<int> result_vec;
    std::deque<int> result_deq;
    void PmergeMeSortVec(int level);
    void PmergeMeSortDeq(int level);
public:
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe & other);
    PmergeMe& operator=(const PmergeMe & other);
    ~PmergeMe();
    class ErrorInputException : public std::exception
    {
        const char *what() throw();
    };
    double PmergeMeSortVec();
    double PmergeMeSortDeq();
};

#endif