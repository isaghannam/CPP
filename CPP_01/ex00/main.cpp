/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:13:26 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/05 11:31:07 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *allocated = newZombie("Allocated");
    randomChump("Chump");
    allocated->announce();
    delete allocated;
    return (0);
}