/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:17:05 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/05 18:10:45 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::PmergeMe(std::vector<std::string> input)
{
    char *end;
    int number;
    for (size_t i = 0; i < input.size(); i++)
    {
        for (size_t j = 0; j < input[i].length(); j++)
        {
            if (!(std::isdigit(input[i][j]) || input[i][j] != ' '))
                throw ErrorInputException();
            number = static_cast<int>(std::strtod(input[i].c_str(), &end));
            if (end[0] != '\0')
                throw ErrorInputException();
            this->input.push_back(number);
        }
    }
    result_vec = this->input;
    for (size_t i = 0; i < this->input.size(); i++)
        result_deq.push_back(this->input[i]);    
}

PmergeMe::PmergeMe(const PmergeMe & other)
    : result_vec(other.result_vec), result_deq(other.result_deq)
{
    
}

PmergeMe& PmergeMe::operator=(const PmergeMe & other)
{
    if (this != &other)
    {
        result_vec = other.result_vec;
        result_deq = other.result_deq;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
    
}

const char *PmergeMe::ErrorInputException::what() throw()
{
    return ("Error");
}

void PmergeMe::PmergeMeSortVec()
{
    
    
    
}