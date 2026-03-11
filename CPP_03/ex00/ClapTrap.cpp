/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:33:25 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/11 15:45:21 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unnamed"), hit_points(10), energy_points(10),
	attack_damage(0)
{
    std::cout << "ClapTrap: default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10),
	energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap: constructor with name parameter (" << name << ") called.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called. ClapTrap: " << this->name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energy_points > 0 && hit_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target 
            << ", causing " << this->attack_damage << " points of damage!\n";
        this->energy_points--;
        return ;
	}
    else if (this->hit_points < 0)
        std::cout << "ClapTrap " << this->name << " has no hit points to attack!\n";
    else
        std::cout << "ClapTrap " << this->name << " has no energy to attack!\n";    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points < 1)
    {
        std::cout << "ClapTrap " << this->name 
            << " is already dead (no hit points left). Stop attcking!\n";
        return ;
    }
    this->hit_points -= amount;
    if (this->hit_points < 0)
        this->hit_points = 0;
    std::cout << "ClapTrap " << this->name << " takes " << amount 
            << " points of damage. Now it has " << this->hit_points << " hit points left!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_points < 1)
    {
        std::cout << "ClapTrap " << this->name << " has no energy points to make a repair!\n";
        return ;
    }
    this->hit_points += amount;
    this->energy_points--;
    std::cout << "ClapTrap " << this->name << " is repaired " << amount 
            << " hit points. Now it has " << this->hit_points << " hit points!\n";
}
