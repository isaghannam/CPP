/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:49:01 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/30 18:40:10 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
MutantStack<T>::MutantStack()
{
    
};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack & other)
    : std::stack<T>(other)
{
    
}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack & other)
{
    if (this != &other)
    {
        std::stack<T>::operator=(other);
    }
    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
    
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin()
{
    return this->c.cbegin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend()
{
    return this->c.cend();
}
