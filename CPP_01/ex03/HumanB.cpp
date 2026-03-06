/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:58:30 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/05 16:05:01 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    
}

void HumanB::attack()
{
    if (!weapon)
        std::cout << name << " attacks with their " << "no weapon!" << std::endl;
    else
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}