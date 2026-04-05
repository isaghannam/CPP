/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:46:06 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/05 12:28:51 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <cmath>

class RPN
{
    private:
        std::string input;
    public:
        RPN(std::string input);
        RPN(const RPN & other);
        RPN & operator=(const RPN & other);
        ~RPN();
        class ErrorInvalidExpressionException : public std::exception
        {
            public:
             const char *what() const throw();
        };
        double processInput();
        void processOperation(std::stack<double> & numbers, char operation);
};



#endif