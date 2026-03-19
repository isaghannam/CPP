/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:44:40 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/16 07:58:55 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : type("Generic WrongAnimal")
{
    cout << "Default WrongAnimal constructor called.\n";
}

WrongAnimal::WrongAnimal(std::string type)
    : type(type)
{
    cout << "WrongAnimal constructor with type " << type << " called.\n";
}

WrongAnimal::~WrongAnimal()
{
    cout << "WrongAnimal destructor called.\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    cout << "WrongAnimal operator '=' called.\n";
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    cout << "WrongAnimal copy constructor called.\n";
    *this = other;
}

void WrongAnimal::makeSound() const
{
    cout << "GENERIC WRONG ANIMAL SOUND\n";
}

std::string WrongAnimal::getType() const
{
    return (type);
}