/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:17:05 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/06 18:55:18 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    std::vector<std::string> input;
    char *end;
    int number;
    for (int i = 1; i < argc; i++)
        input.push_back(argv[i]);
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

double PmergeMe::PmergeMeSortVec()
{
    clock_t t;
    t = clock();
    PmergeMeSortVec(0);
    t = clock() - t;
    return (static_cast<double>(t) * 1000000.0/CLOCKS_PER_SEC);
}

void PmergeMe::PmergeMeSortVec(int level)
{
    int chunk_size = 1 << level;
    int number_of_elements = result_vec.size() / chunk_size;
    if (number_of_elements < 2)
        return ;
    for (int i = 0; i <= static_cast<int>(result_vec.size()) - 2 * chunk_size; i += (2 * chunk_size))
    {
        if (result_vec[i + chunk_size - 1] > result_vec[i + 2 * chunk_size - 1])
        {
            for (int j = 0; j < chunk_size; j++)
                std::swap(result_vec[i + j], result_vec[i + chunk_size + j]);
        }
    }
    PmergeMeSortVec(level + 1);
    
    
    
}

double PmergeMe::PmergeMeSortDeq()
{
    clock_t t;
    t = clock();
    PmergeMeSortDeq(0);
    t = clock() - t;
    return (static_cast<double>(t) * 1000000.0/CLOCKS_PER_SEC);
}

void PmergeMe::PmergeMeSortDeq(int level)
{
    
}