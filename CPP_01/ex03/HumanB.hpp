/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:50:18 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/05 15:57:27 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weapon;
public:
    HumanB(std::string name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon& weapon);
};




#endif