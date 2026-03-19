/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:46:39 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/18 10:37:35 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat"), brain(new Brain("Generic cat idea"))
{
    cout << "Default Cat constructor called.\n";
}

Cat::Cat(std::string idea)
    : Animal("Cat"), brain(new Brain(idea))
{
    cout << "Cat constructor with idea called.\n";
}

Cat::~Cat()
{
    delete this->brain;
    cout << "Cat destructor called.\n";
}

Cat& Cat::operator=(const Cat& other)
{
    cout << "Cat operator '=' called.\n";
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

Cat::Cat(const Cat& other)
    : Animal("Cat"), brain(new Brain(*other.brain))
{
    cout << "Cat copy constructor called.\n";
}

void Cat::makeSound() const
{
    cout << "MEAW MEAW MEAW\n";
}

const std::string *Cat::get_brain()
{
    return(brain->get_ideas());
}

void Cat::set_brain(int i, const std::string& idea)
{
    brain->set_idea(i, idea);
}

const std::string Cat::get_idea(int i)
{
    return(brain->get_idea(i));
}