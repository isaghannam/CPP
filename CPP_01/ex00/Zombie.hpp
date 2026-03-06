/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:47:47 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/05 11:25:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string name);
        Zombie();
        ~Zombie();
        void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif