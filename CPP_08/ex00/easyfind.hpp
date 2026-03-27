/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:19:07 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/27 15:42:04 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T & container, const int & find)
{
    typename T::iterator found = std::find(container.begin(), container.end(),find);
    if (found == container.end())
        throw std::exception();
    return found;
}


#endif