/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:03:09 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/12 14:13:41 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        /* data */
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap& operator=(const FragTrap& other);
        FragTrap(const FragTrap& other);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
};


#endif