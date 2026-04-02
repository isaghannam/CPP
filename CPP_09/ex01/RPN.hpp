/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:46:06 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/02 18:43:54 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
    private:
        std::string input;
        std::stack<int> numbers;
    public:
        RPN(std::string input);
        RPN(const RPN & other);
        RPN & operator=(const RPN & other);
        ~RPN();
        class ErrorInvalidCharacters : std::exception
        {
            public:
             const char *what() const throw();
        };
        class ErrorInvalidExpression : std::exception
        {
            public:
             const char *what() const throw();
        };
        void processNextToken();
};



#endif