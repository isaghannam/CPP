/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:50:35 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/05 16:04:23 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
    
}

std::string Weapon::getType(void) const
{
    return (this->type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}