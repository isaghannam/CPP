/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:46:03 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/02 18:42:21 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input)
    : input(input)
{
        
}

RPN::RPN(const RPN & other)
{
    
}

RPN & RPN::operator=(const RPN & other)
{
    
}

RPN::~RPN()
{
    
}

const char * RPN::ErrorInvalidCharacters::what() const throw()
{
    return ("Error: invalid characters in input.");
}

const char * RPN::ErrorInvalidExpression::what() const throw()
{
    return ("Error: invalid expression.");
}