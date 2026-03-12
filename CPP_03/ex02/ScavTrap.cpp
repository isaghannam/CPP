/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:03:06 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/11 16:36:43 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("Unnamed", 100, 50, 20)
{
    std::cout << "ScavTrap: default constructor called.\n";
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap: constructor with name parameter (" << name << ") called.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap: operator = called.\n";
    if (this != &other)
        ClapTrap::operator=(other);                                                                                                        
    return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap: copy constructor called.\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called. ScavTrap: " << this->name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energy_points > 0 && hit_points > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target 
            << ", causing " << this->attack_damage << " points of damage!\n";
        this->energy_points--;
        return ;
	}
    else if (this->hit_points < 0)
        std::cout << "ScavTrap " << this->name << " has no hit points to attack!\n";
    else
        std::cout << "ScavTrap " << this->name << " has no energy to attack!\n";  
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!\n";
}