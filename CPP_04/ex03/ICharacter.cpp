/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:12:50 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/19 15:41:07 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
    (void)other;
    return (*this);
}

ICharacter::ICharacter(const ICharacter& other)
{
    (void)other;
}