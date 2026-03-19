/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:49:04 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/19 15:51:01 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character()
    : ICharacter(), name("Default name")
{
    for (size_t i = 0; i < 4; i++)
        inventory[i] = NULL; 
}

Character::Character(std::string name)
    : ICharacter(), name(name)
{
    for (size_t i = 0; i < 4; i++)
        inventory[i] = NULL; 
}

Character::Character(const Character& other)
    : ICharacter()
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->name = other.name;
        for (size_t i = 0; i < 4; i++)
        {
            delete inventory[i];
            if (other.inventory[i] != NULL)
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        } 
    }
    return (*this);
}

Character::~Character()
{
    for (size_t i = 0; i < 4; i++)
        delete inventory[i];
}

std::string const & Character::getName() const
{
    return (name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (size_t i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx > -1 && idx < 4)
        inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx > -1 && idx < 4 && inventory[idx])
    {
        inventory[idx]->use(target);
    }
}
