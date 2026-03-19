/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:38:53 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/16 16:20:45 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(std::string idea);
        ~Cat();
        Cat& operator=(const Cat& other);
        Cat(const Cat& other);
        void makeSound() const;
        const std::string *get_brain();
        const std::string get_idea(int i);
        void set_brain(int i, const std::string& idea);
};



#endif