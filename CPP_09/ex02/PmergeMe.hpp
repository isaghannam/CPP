/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:17:01 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/05 18:07:17 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <cmath>

class PmergeMe
{
private:
    PmergeMe();
    std::vector<int> input;
    std::vector<int> result_vec;
    std::deque<int> result_deq;
public:
    PmergeMe(std::vector<std::string> input);
    PmergeMe(const PmergeMe & other);
    PmergeMe& operator=(const PmergeMe & other);
    ~PmergeMe();
    class ErrorInputException : public std::exception
    {
        const char *what() throw();
    };
    void PmergeMeSortVec();
    
};

#endif