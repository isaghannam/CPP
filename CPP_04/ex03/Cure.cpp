/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:12:42 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/19 15:26:58 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
    : AMateria("cure")
{
    
}

Cure::Cure(const Cure& other)
    : AMateria(other)
{
    
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        this->AMateria::operator=(other);
    }
    return (*this);    
}

Cure::~Cure()
{
    
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
