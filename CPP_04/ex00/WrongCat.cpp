/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:46:39 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/14 17:04:09 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal("WrongCat")
{
    cout << "Default WrongCat constructor called.\n";
}

WrongCat::~WrongCat()
{
    cout << "WrongCat destructor called.\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    cout << "WrongCat operator '=' called.\n";
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal("WrongCat")
{
    cout << "WrongCat copy constructor called.\n";
    *this = other;
}

void WrongCat::makeSound() const
{
    cout << "MEAW MEAW MEAW\n";
}