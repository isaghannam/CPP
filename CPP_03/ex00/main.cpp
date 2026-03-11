/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:42:16 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/11 15:46:27 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap one("One");
    one.attack("Two");
    one.takeDamage(5);
    one.takeDamage(15);
    one.beRepaired(50);
    one.beRepaired(50);
    one.beRepaired(50);
    one.beRepaired(50);
    one.beRepaired(50);
    one.beRepaired(50);
    one.beRepaired(50);
    one.beRepaired(50);
    one.beRepaired(50);
    one.beRepaired(50);
    one.beRepaired(50);
    return (0);
}
