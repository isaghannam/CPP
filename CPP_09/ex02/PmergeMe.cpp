/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:17:05 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/08 18:34:53 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	char	*end;
	int		number;

	std::vector<std::string> input;
	for (int i = 1; i < argc; i++)
		input.push_back(argv[i]);
	for (size_t i = 0; i < input.size(); i++)
	{
		for (size_t j = 0; j < input[i].length(); j++)
		{
			if (!(std::isdigit(input[i][j]) || input[i][j] != ' '))
				throw ErrorInputException();
			number = static_cast<int>(strtod(input[i].c_str(), &end));
			if (end[0] != '\0' || number < 0)
				throw ErrorInputException();
		}
		this->input.push_back(number);
	}
	result_vec = this->input;
	for (size_t i = 0; i < this->input.size(); i++)
		result_deq.push_back(this->input[i]);
	jacobsthal_numbers = jacobsthalOrder();
}

PmergeMe::PmergeMe(const PmergeMe &other) : result_vec(other.result_vec),
	result_deq(other.result_deq), jacobsthal_numbers(other.jacobsthal_numbers)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		result_vec = other.result_vec;
		result_deq = other.result_deq;
		jacobsthal_numbers = other.jacobsthal_numbers;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

const char *PmergeMe::ErrorInputException::what() const throw()
{
	return ("Error");
}

double PmergeMe::PmergeMeSortVec()
{
	clock_t	t;

	t = clock();
	PmergeMeSortVec(0);
	t = clock() - t;
	return (static_cast<double>(t) * 1000000.0 / CLOCKS_PER_SEC);
}

void PmergeMe::PmergeMeSortVec(int level)
{
	int	chunk_size;
	int	number_of_elements;
	int	j_number;
	int	local_to_insert;
	int	a;

	chunk_size = 1 << level;
	number_of_elements = result_vec.size() / chunk_size;
	j_number = 0;
	a = 0;
	if (number_of_elements < 2)
		return ;
	for (int i = 0; i <= static_cast<int>(result_vec.size()) - 2 * chunk_size; i
		+= (2 * chunk_size))
	{
		if (result_vec[i + chunk_size - 1] > result_vec[i + 2 * chunk_size - 1])
		{
			for (int j = 0; j < chunk_size; j++)
				std::swap(result_vec[i + j], result_vec[i + chunk_size + j]);
		}
	}
	PmergeMeSortVec(level + 1);
	std::vector<int> main;
	std::vector<int> pend;
	for (int i = 0; i < number_of_elements; i++)
	{
		if (i == 0 || (i % 2 == 1)) // main
		{
			for (int j = 0; j < chunk_size; j++)
				main.push_back(result_vec[i * chunk_size + j]);
		}
		else // pend
		{
			for (int j = 0; j < chunk_size; j++)
				pend.push_back(result_vec[i * chunk_size + j]);
		}
	}
	for (int i = 1; jacobsthal_numbers[i] < (static_cast<int>(pend.size())
			/ chunk_size); i++)
	{
		j_number = jacobsthal_numbers[i];
		for (int j = j_number - 1; j >= jacobsthal_numbers[i - 1]; j--)
		{
			a = result_vec[(j + 1) * 2 * chunk_size - 1];
            
			local_to_insert = binarySearch(main, pend[(j + 1) * chunk_size - 1],
					findElementPos(main, a, chunk_size) + 1, chunk_size);
			main.insert(main.begin() + local_to_insert * chunk_size,
				pend.begin() + j * chunk_size, pend.begin() + (j + 1)
				* chunk_size);
		}
	}
	for (int i = (static_cast<int>(pend.size()) / chunk_size) - 1; i > j_number
		- 1; i--)
	{
		local_to_insert = binarySearch(main, pend[(i + 1) * chunk_size - 1],
				main.size() / chunk_size, chunk_size);
		main.insert(main.begin() + local_to_insert * chunk_size, pend.begin()
			+ i * chunk_size, pend.begin() + (i + 1) * chunk_size);
	}
	for (size_t i = main.size(); i < result_vec.size(); i++)
		main.push_back(result_vec[i]);
	result_vec = main;
}

double PmergeMe::PmergeMeSortDeq()
{
	clock_t	t;

	t = clock();
	PmergeMeSortDeq(0);
	t = clock() - t;
	return (static_cast<double>(t) * 1000000.0 / CLOCKS_PER_SEC);
}

void PmergeMe::PmergeMeSortDeq(int level)
{
	int	chunk_size;
	int	number_of_elements;
	int	j_number;
	int	local_to_insert;
	int	a;

	chunk_size = 1 << level;
	number_of_elements = result_deq.size() / chunk_size;
	j_number = 0;
	a = 0;
	if (number_of_elements < 2)
		return ;
	for (int i = 0; i <= static_cast<int>(result_deq.size()) - 2 * chunk_size; i
		+= (2 * chunk_size))
	{
		if (result_deq[i + chunk_size - 1] > result_deq[i + 2 * chunk_size - 1])
		{
			for (int j = 0; j < chunk_size; j++)
				std::swap(result_deq[i + j], result_deq[i + chunk_size + j]);
		}
	}
	PmergeMeSortDeq(level + 1);
	std::deque<int> main;
	std::deque<int> pend;
	for (int i = 0; i < number_of_elements; i++)
	{
		if (i == 0 || (i % 2 == 1)) // main
		{
			for (int j = 0; j < chunk_size; j++)
				main.push_back(result_deq[i * chunk_size + j]);
		}
		else // pend
		{
			for (int j = 0; j < chunk_size; j++)
				pend.push_back(result_deq[i * chunk_size + j]);
		}
	}
	for (int i = 1; jacobsthal_numbers[i] < (static_cast<int>(pend.size())
			/ chunk_size); i++)
	{
		j_number = jacobsthal_numbers[i];
		for (int j = j_number - 1; j >= jacobsthal_numbers[i - 1]; j--)
		{
			a = result_deq[(j + 1) * 2 * chunk_size - 1];
			local_to_insert = binarySearch(main, pend[(j + 1) * chunk_size - 1],
					findElementPos(main, a, chunk_size) + 1, chunk_size);
			main.insert(main.begin() + local_to_insert * chunk_size,
				pend.begin() + j * chunk_size, pend.begin() + (j + 1)
				* chunk_size);
		}
	}
	for (int i = (static_cast<int>(pend.size()) / chunk_size) - 1; i > j_number
		- 1; i--)
	{
		local_to_insert = binarySearch(main, pend[(i + 1) * chunk_size - 1],
				main.size() / chunk_size, chunk_size);
		main.insert(main.begin() + local_to_insert * chunk_size, pend.begin()
			+ i * chunk_size, pend.begin() + (i + 1) * chunk_size);
	}
	for (size_t i = main.size(); i < result_deq.size(); i++)
		main.push_back(result_deq[i]);
	result_deq = main;
}

std::vector<int> PmergeMe::jacobsthalOrder()
{
	std::vector<int> order;
	order.push_back(1);
	order.push_back(3);
	while (order.back() < static_cast<int>(result_vec.size()))
		order.push_back(2 * order[order.size() - 2] + order.back());
    order[0] = 0;
	return (order);
}

const std::vector<int>& PmergeMe::getResultVec() const
{
    return result_vec;
}

const std::deque<int>& PmergeMe::getResultDeq() const
{
    return result_deq;
}

const std::vector<int>& PmergeMe::getInput() const
{
    return input;
}

std::ostream& operator<<(std::ostream& os, const PmergeMe& pmergeme)
{
    std::vector<int> result = pmergeme.getResultVec();
    std::vector<int> input = pmergeme.getInput();
    os << "Before:  ";
    for (size_t i = 0; i < input.size() - 1; i++)
        os << input[i] << " ";
    os << input[input.size() - 1] << std::endl;
    os << "After:   ";
    for (size_t i = 0; i < result.size() - 1; i++)
        os << result[i] << " ";
    os << result[result.size() - 1] << std::endl;
    return os;
}
