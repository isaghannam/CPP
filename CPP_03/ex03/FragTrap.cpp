/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:03:06 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/12 14:13:19 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("Unnamed", 100, 100, 30)
{
    std::cout << "FragTrap: default constructor called.\n";
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap: constructor with name parameter (" << name << ") called.\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap: operator = called.\n";
    if (this != &other)
        ClapTrap::operator=(other);                                                                                                        
    return (*this);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap: copy constructor called.\n";
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called. FragTrap: " << this->name << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->energy_points > 0 && hit_points > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target 
            << ", causing " << this->attack_damage << " points of damage!\n";
        this->energy_points--;
        return ;
	}
    else if (this->hit_points < 0)
        std::cout << "FragTrap " << this->name << " has no hit points to attack!\n";
    else
        std::cout << "FragTrap " << this->name << " has no energy to attack!\n";  
}

void FragTrap::highFivesGuys(void)
{
     std::cout << "FragTrap " << this->name << " gives a HIGH FIVE GUYS!\n";
     std::cout << "  ⠀⠀   ⢀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl
			   << "⠀⠀⠀⠀⠀⠀⠀⠘⣷⣤⡀⠀⠀⠀⠀⣰⣿⡄⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀" << std::endl
			   << "⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣦⡀⢀⣼⣿⣿⣧⠀⠀⢀⣠⣶⣿⡿⠀⠀⠀⠀⠀" << std::endl
			   << "⠀⣀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣾⣿⣿⣿⣿⣦⣾⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀" << std::endl
			   << "⠀⠈⠻⣿⣿⣶⣶⣶⣬⣿⣿⣿⠀⢸⣿⣿⡏⠀⣸⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀" << std::endl
			   << "⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⠀⢸⣿⡿⠀⢰⣿⣿⠟⠉⣿⣿⣷⣶⣶⡶⠀⠀" << std::endl
			   << "⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⠀⠸⣿⠁⢀⣿⡿⠃⢠⣾⣿⣿⣿⣿⡟⠁⠀⠀" << std::endl
			   << "⠀⠀⠀⠀⢀⣤⣾⣷⡀⠈⠻⣇⠀⠀⠀⠀⠘⠟⠁⣴⣿⡿⠟⢿⣿⠏⠀⠀⠀⠀" << std::endl
			   << "⠀⠀⢀⣴⣿⣿⣿⣿⣿⣆⠀⠉⠀⠀⠀⠀⠀⠀⠀⠛⠋⣀⣴⣾⣿⣆⠀⠀⠀⠀" << std::endl
			   << "⠀⠀⠙⠛⠛⠿⠿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣷⡀⠀⠀" << std::endl
			   << "⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣷⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⠛⠛⠛⠛⠻⠿⠿⠦⠀" << std::endl
			   << "⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⠇⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl
			   << "⠀⠀⠀⠀⠀⠀⠛⠛⠉⠉⠀⠀⠀⠀⠀⢸⡿⠛⢿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl
			   << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡞⠁⠀⠀⠙⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl
			   << "           HI-FIVE" << std::endl;
}
