/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:46:03 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/05 12:37:00 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input)
    : input(input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (i % 2 == 0)
        {
            if (!(std::isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'))
                throw ErrorInvalidExpressionException();
        }
        else
        {
            if (input[i] != ' ')
                throw ErrorInvalidExpressionException();
        }
    }            
}

RPN::RPN(const RPN & other)
    : input(other.input)
{
    
}

RPN & RPN::operator=(const RPN & other)
{
    if (this != &other)
    {
        input = other.input;
    }
    return *this;
}

RPN::~RPN()
{
    
}

const char * RPN::ErrorInvalidExpressionException::what() const throw()
{
    return ("Error");
}

double RPN::processInput()
{    
    std::stack<double> numbers;
    for (size_t i = 0; i < input.length(); i++)
    {
        switch (input[i])
        {
            case ' ':
                break;
            case '+':
                processOperation(numbers, '+');
                break;
            case '-':
                processOperation(numbers, '-');
                break;
            case '*':
                processOperation(numbers, '*');
                break;
            case '/':
                processOperation(numbers, '/');
                break;
            default:
                numbers.push(input[i] - '0');
                break;
        }        
    }
    if (numbers.size() > 1)
        throw ErrorInvalidExpressionException();
    return numbers.top();
}

void RPN::processOperation(std::stack<double>& numbers, char operation)
{
    double top;
    double second_top;
    double result;
    if (numbers.size() < 2)
        throw ErrorInvalidExpressionException();
    top = numbers.top();
    numbers.pop();
    second_top = numbers.top();
    numbers.pop();
    switch (operation)
    {
        case '+':
            result = second_top + top;
            break;
        case '-':
            result = second_top - top;
            break;
        case '*':
            result = second_top * top;
            break;
        case '/':
            result = second_top / top;
            break;
        default:
            break;
    }
    if (std::isnan(result) || std::isinf(result))
        throw ErrorInvalidExpressionException();
    numbers.push(result);
}
