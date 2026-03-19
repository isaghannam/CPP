/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 08:49:58 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/16 15:46:19 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (size_t i = 0; i < 100; i++)
        this->ideas[i] = "Generic brain idea";
}

Brain::Brain(std::string idea)
{
    for (size_t i = 0; i < 100; i++)
        this->ideas[i] = idea;
}

Brain::~Brain()
{
    cout << "Brain destructor called.\n";
}

Brain::Brain(const Brain& other)
{
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

const std::string *Brain::get_ideas() const
{
    return (this->ideas);
}

const std::string Brain::get_idea(int i) const
{
    return (ideas[i]);
}

void Brain::set_idea(int i, const std::string& idea)
{
    ideas[i] = idea;
}