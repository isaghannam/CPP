/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:58:37 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/26 14:16:37 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T & x, T & y)
{
    T temp = x;
    x = y;
    y = temp;
}

template<typename T>
T const & min(T const & x, T const & y)
{
    return (x >= y ? y : x);
}

template<typename T>
T const & max(T const & x, T const & y)
{
    return (x >= y ? x : y);
}

#endif