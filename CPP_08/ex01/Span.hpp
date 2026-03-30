/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:47:26 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/30 17:35:32 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    private:
        Span();
        std::vector<int> _numbers;
        unsigned int _maxSize;
    public:
        Span(unsigned int N);
        Span(const Span & other);
        Span& operator=(const Span & other);
        ~Span();
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        class TooManyNumbersException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class NoSpanPossibleException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        template<typename InputIterator>
        void addNumbers(InputIterator start, InputIterator finish);
        std::vector<int> & getNumbers();
        unsigned int & getMaxSize();
};

#include "Span.tpp"


#endif