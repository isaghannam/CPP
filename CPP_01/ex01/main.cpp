/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:13:26 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/05 13:23:49 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "create, annouce & delete horde with 5 zombies:\n";
    Zombie *horde = zombieHorde(5, "horde_name");
    for (int i = 0; i < 5; i++)
        horde[i].announce();
    delete []horde;

    std::cout << "\ncreate, annouce & delete horde with 3 zombies:\n";
    horde = zombieHorde(3, "horde_name_three");
    for (int i = 0; i < 3; i++)
        horde[i].announce();
    delete []horde;
    return (0);
}
