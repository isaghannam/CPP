/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:48:57 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/30 18:24:48 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        MutantStack();
        MutantStack(const MutantStack & other);
        MutantStack & operator=(const MutantStack & other);
        ~MutantStack();
        iterator begin();
        iterator end();
        const_iterator cbegin();
        const_iterator cend();
};


#include "MutantStack.tpp"


#endif