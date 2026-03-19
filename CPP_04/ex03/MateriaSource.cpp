/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:42:40 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/19 15:37:24 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
    : IMateriaSource()
{
    for (size_t i = 0; i < 4; i++)
        materias_learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
    : IMateriaSource()
{
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < 4; i++)
        {
            delete (this->materias_learned[i]);
            if (other.materias_learned[i] == NULL)
                this->materias_learned[i] = NULL;
            else
                this->materias_learned[i] = other.materias_learned[i]->clone();
        }
    }
    return (*this);    
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
        delete (this->materias_learned[i]);
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;
    
    for (size_t i = 0; i < 4; i++)
    {
        if (this->materias_learned[i] == NULL)
        {
            this->materias_learned[i] = m->clone();
            return ;
        }
    }
    
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (materias_learned[i] && materias_learned[i]->getType() == type)
            return materias_learned[i]->clone();
    }
    return 0;
}