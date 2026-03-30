/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:33:48 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/30 15:35:24 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
    : _maxSize(0)
{
    
}

Span::Span(unsigned int N)
    : _maxSize(N)
{
    
}

Span::Span(const Span & other)
    : _numbers(other._numbers), _maxSize(other._maxSize)
{
    
}

Span& Span::operator=(const Span & other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
    
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw TooManyNumbersException();
    _numbers.push_back(number);
}

int Span::shortestSpan()
{
    if (_numbers.size() <=1)
        throw NoSpanPossibleException();
    std::sort(_numbers.begin(), _numbers.end());
    int span = _numbers.at(1) - _numbers.at(0);
    int span_temp = 0;
    for (size_t i = 1; i < _numbers.size() - 1; i++)
    {
        span_temp = _numbers.at(i + 1) - _numbers.at(i);
        if (span_temp < span)
            span = span_temp;
    }
    return span;
}

int Span::longestSpan()
{
    if (_numbers.size() <=1)
        throw NoSpanPossibleException();
    std::sort(_numbers.begin(), _numbers.end());
    return (_numbers.back() - _numbers.front());
}

const char *Span::TooManyNumbersException::what() const throw()
{
    return ("Cannot insert number(s). Vector with numbers already full or does not comport all you want to insert.");
}

const char *Span::NoSpanPossibleException::what() const throw()
{
    return ("Not enough numbers to calculate span.");
}

std::vector<int> & Span::getNumbers()
{
    return _numbers;
}

unsigned int & Span::getMaxSize()
{
    return _maxSize;
}