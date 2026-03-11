/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:03:09 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/11 16:27:24 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        /* data */
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap& operator=(const ScavTrap& other);
        ScavTrap(const ScavTrap& other);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
        
};


#endif