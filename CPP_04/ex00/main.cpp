/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:25:15 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/19 16:20:18 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    cout << "Test with correct implementation but no allocation and no definition of animal as Cat or Dog\n";
    {
        Animal generic_animal;
        generic_animal.makeSound();
        Cat cat_one;
        cat_one.makeSound();
        Dog dog_one;
        dog_one.makeSound();
    }

    cout << "\n\n\nTest with wrong implementation but no allocation and no definition of animal as Cat or Dog\n";
    {
        WrongAnimal generic_animal;
        generic_animal.makeSound();
        WrongCat cat_one;
        cat_one.makeSound();
    }

    cout << "\n\n\nTest with correct implementation and allocation and definition of animal as Cat or Dog\n";
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
        delete j;
    }

    cout << "\n\n\nTest with wrong implementation and allocation and definition of animal as Cat\n";
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the generic sound!
        meta->makeSound();
        delete meta;
        delete i;
    }
        
    return (0);
}