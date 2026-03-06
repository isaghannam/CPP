/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:53:37 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/05 11:29:22 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::Zombie()
{
    this->name = "Zombie not named";
}

Zombie::~Zombie(void)
{
    std::cout << name << ": deleted\n";
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie *newZombie(std::string name)
{
    Zombie *new_zombie = new Zombie(name);
    return (new_zombie);
}

void randomChump(std::string name)
{
    Zombie chump_zombie(name);
    chump_zombie.announce();
}

