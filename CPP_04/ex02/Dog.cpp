/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:43:16 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/16 16:25:56 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
    : Animal("Dog"), brain(new Brain("Generic dog idea"))
{
    cout << "Default Dog constructor called.\n";
}

Dog::Dog(std::string idea)
    : Animal("Dog"), brain(new Brain(idea))
{
    cout << "Dog constructor with idea called.\n";
}

Dog::~Dog()
{
    delete this->brain;
    cout << "Dog destructor called.\n";
}

Dog& Dog::operator=(const Dog& other)
{
    cout << "Dog operator '=' called.\n";
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::Dog(const Dog& other)
    : Animal("Dog"), brain(new Brain(*other.brain))
{
    cout << "Dog copy constructor called.\n";
}

void Dog::makeSound() const
{
    cout << "WOUF WOUF WOUF\n";
}

const std::string *Dog::get_brain()
{
    return(brain->get_ideas());
}

void Dog::set_brain(int i, const std::string& idea)
{
    brain->set_idea(i, idea);
}

const std::string Dog::get_idea(int i)
{
    return(brain->get_idea(i));
}