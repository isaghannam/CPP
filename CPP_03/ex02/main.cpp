/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:42:16 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/12 11:14:01 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap one("One");
    ScavTrap two("Two");
    one.attack("Two");
    one.takeDamage(5);
    one.takeDamage(15);
    one.beRepaired(50);
    two.attack("One");
    two.takeDamage(15);
    two.beRepaired(2);
    two.guardGate();
    FragTrap three("Three");
    three.attack("One");
    three.takeDamage(10);
    three.highFivesGuys();
    return (0);
}
