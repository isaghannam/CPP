/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:58:12 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/05 15:54:55 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
    : name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
    
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
    this->weapon = weapon;
}