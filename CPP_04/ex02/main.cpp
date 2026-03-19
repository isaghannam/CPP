/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:25:15 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/18 10:10:53 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Dog.hpp"
// #include "Cat.hpp"

// int main(void)
// {
//     int half = 2;
//     Animal *animal_array[half * 2];
//     for (int i = 0; i < (half * 2); i++)
//     {
//         if (i < half)
//             animal_array[i] = new Cat("Cat idea");
//         else
//             animal_array[i] = new Dog("Dog idea");
//     }
//     for (int i = 0; i < (half * 2); i++)
//         delete animal_array[i];
//     return (0);
// }

#include "Dog.hpp"
#include "Cat.hpp"

#define SIZE 6

int main()
{
    //Animal a;
    std::cout << "\n=============================\n";
    std::cout << "TEST 1: Array of Animals\n";
    std::cout << "=============================\n\n";

    Animal* animals[SIZE];

    for (int i = 0; i < SIZE/2; i++)
        animals[i] = new Dog();

    for (int i = SIZE/2; i < SIZE; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Animal Sounds ---\n";

    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting Animals ---\n";

    for (int i = 0; i < SIZE; i++)
        delete animals[i];


    std::cout << "\n=============================\n";
    std::cout << "TEST 2: Deep Copy Dog\n";
    std::cout << "=============================\n\n";

    Dog originalDog;
    originalDog.set_brain(0, "Chase the ball");

    Dog copyDog = originalDog;

    std::cout << "\nOriginal idea: "
              << originalDog.get_idea(0) << std::endl;

    std::cout << "Copy idea: "
              << copyDog.get_idea(0) << std::endl;

    copyDog.set_brain(0, "Eat food");

    std::cout << "\nAfter modifying copy:\n";

    std::cout << "Original idea: "
              << originalDog.get_idea(0) << std::endl;

    std::cout << "Copy idea: "
              << copyDog.get_idea(0) << std::endl;


    std::cout << "\n=============================\n";
    std::cout << "TEST 3: Deep Copy Cat\n";
    std::cout << "=============================\n\n";

    Cat originalCat;
    originalCat.set_brain(0, "Sleep");

    Cat copyCat(originalCat);

    std::cout << "\nOriginal idea: "
              << originalCat.get_idea(0) << std::endl;

    std::cout << "Copy idea: "
              << copyCat.get_idea(0) << std::endl;

    copyCat.set_brain(0, "Destroy sofa");

    std::cout << "\nAfter modifying copy:\n";

    std::cout << "Original idea: "
              << originalCat.get_idea(0) << std::endl;

    std::cout << "Copy idea: "
              << copyCat.get_idea(0) << std::endl;

    std::cout << "\n=============================\n";
    std::cout << "END OF TESTS\n";
    std::cout << "=============================\n\n";

    return 0;
}