/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:44:40 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/18 10:36:36 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
    : type("Generic animal")
{
    cout << "Default animal constructor called.\n";
}

Animal::Animal(std::string type)
    : type(type)
{
    cout << "Animal constructor with type " << type << " called.\n";
}

Animal::~Animal()
{
    cout << "Animal destructor called.\n";
}

Animal& Animal::operator=(const Animal& other)
{
    cout << "Animal operator '=' called.\n";
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Animal::Animal(const Animal& other)
{
    cout << "Animal copy constructor called.\n";
    *this = other;
}

void Animal::makeSound() const
{
    cout << "GENERIC ANIMAL SOUND\n";
}

std::string Animal::getType() const
{
    return (type);
}