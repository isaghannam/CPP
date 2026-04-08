/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:17:01 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/08 18:34:58 by ighannam         ###   ########.fr       */
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
    std::vector<int> jacobsthal_numbers;
    void PmergeMeSortVec(int level);
    void PmergeMeSortDeq(int level);
public:
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe & other);
    PmergeMe& operator=(const PmergeMe & other);
    ~PmergeMe();
    class ErrorInputException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    double PmergeMeSortVec();
    double PmergeMeSortDeq();
    std::vector<int> jacobsthalOrder();
    const std::vector<int>& getResultVec() const;
    const std::deque<int>& getResultDeq() const;
    const std::vector<int>& getInput() const;
};

std::ostream & operator<<(std::ostream& os, const PmergeMe& pemergeme);

template<typename T>
int findElementPos(T main, int to_find, int chunck_size)
{
    for (int i = 0; i < static_cast<int>(main.size()) / chunck_size - 1; i++)
    {
        if (main[(i + 1) * chunck_size - 1] == to_find)
            return i;
    }
    return 0;
}

template<typename T>
int binarySearch(T main, int search, int bound, int chunk_size)
{
    int start = 0;
	int mid = bound / 2;
	while (start < bound)
	{
		if (main[(mid + 1) * chunk_size - 1] > search)
		{
			bound = mid;
			mid = start + (bound - start) / 2;
		}
		else if (main[(mid + 1) * chunk_size - 1] < search)
		{
			start = mid + 1;
			mid = start + (bound - start) / 2;
		}
		else
			return (mid);
	}
	return (start);
}


#endif