/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:57:19 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/19 16:19:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void separator(std::string title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("SUBJECT BASIC TEST");

    IMateriaSource* src = new MateriaSource();
    AMateria *new_ice = new Ice();
    AMateria *new_cure = new Cure();
    src->learnMateria(new_ice);
    src->learnMateria(new_cure);

    ICharacter* me = new Character("me");

    AMateria* tmp_ice;
    AMateria* tmp_cure;

    tmp_ice = src->createMateria("ice");
    me->equip(tmp_ice);

    tmp_cure = src->createMateria("cure");
    me->equip(tmp_cure);

    ICharacter* bob = new Character("bob");

    std::cout << "\nEXPECTED:\n";
    std::cout << "* shoots an ice bolt at bob *\n";
    std::cout << "* heals bob's wounds *\n";

    std::cout << "\nRESULT:\n";
    me->use(0, *bob);
    me->use(1, *bob);

    separator("INVALID INDEX TEST");

    std::cout << "\nEXPECTED:\n(nothing)\n";
    std::cout << "\nRESULT:\n";
    me->use(-1, *bob);
    me->use(42, *bob);

    separator("FULL INVENTORY TEST");

    AMateria* m1 = src->createMateria("ice");
    AMateria* m2 = src->createMateria("ice");
    AMateria* m3 = src->createMateria("ice");

    me->equip(m1);
    me->equip(m2);
    me->equip(m3); // should ignore (full inventory)

    std::cout << "\nEXPECTED:\n";
    std::cout << "Slot 0-3 usados, extra ignorado\n";

    std::cout << "\nRESULT:\n";
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);

    separator("UNEQUIP TEST");

    std::cout << "\nEXPECTED:\n";
    std::cout << "Slot 1 vazio (não faz nada)\n";

    std::cout << "\nRESULT:\n";
    me->unequip(1);
    me->use(1, *bob); // nothing should happen

    separator("DEEP COPY TEST");

    Character* original = new Character("original");
    AMateria *original_ice = src->createMateria("ice");
    original->equip(original_ice);
    original->equip(src->createMateria("cure"));

    Character* copy = new Character(*original);

    std::cout << "\nEXPECTED:\n";
    std::cout << "Original and copy function independently\n";

    std::cout << "\nRESULT:\n";
    original->use(0, *bob);
    copy->use(0, *bob);

    separator("MODIFY ORIGINAL AFTER COPY");

    original->unequip(0);

    std::cout << "\nEXPECTED:\n";
    std::cout << "Original does not use slot 0 anymore\n";
    std::cout << "Copy still works\n";

    std::cout << "\nRESULT:\n";
    original->use(0, *bob); // nada
    copy->use(0, *bob);     // ainda funciona

    separator("UNKNOWN TYPE TEST");

    AMateria* unknown = src->createMateria("fire");

    std::cout << "\nEXPECTED:\nNULL\n";
    std::cout << "RESULT:\n";
    std::cout << (unknown == NULL ? "NULL\n" : "NOT NULL\n");

    separator("CLEANUP");

    delete unknown;
    delete copy;
    delete original;
    delete bob;
    delete me;
    delete src;
    delete new_ice;
    delete new_cure;
    delete m3;
    delete tmp_cure;
    delete original_ice;

    return 0;
}

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     AMateria* tmp_ice = new Ice();
//     src->learnMateria(tmp_ice);
//     AMateria* tmp_cure = new Cure();
//     src->learnMateria(tmp_cure);
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     delete tmp_cure;
//     delete tmp_ice;
//     return 0;
// }