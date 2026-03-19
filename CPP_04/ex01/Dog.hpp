/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:40:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/16 16:20:49 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(std::string idea);
        ~Dog();
        Dog& operator=(const Dog& other);
        Dog(const Dog& other);
        void makeSound() const;
        const std::string *get_brain();
        const std::string get_idea(int i);
        void set_brain(int i, const std::string& idea);
};



#endif