/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:47:26 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/27 16:52:55 by ighannam         ###   ########.fr       */
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
    Span(){};
    std::vector<int> _numbers;
public:
    Span(unsigned int N);
    Span(const Span & other);
    Span& operator=(const Span & other);
    ~Span();
};




#endif