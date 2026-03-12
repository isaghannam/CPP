/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:42:16 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/12 15:47:47 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n===== DEFAULT CONSTRUCTOR TEST =====\n";
    DiamondTrap a;

    std::cout << "\nExpected whoAmI():\n";
    std::cout << "DiamondTrap name: Unnamed\n";
    std::cout << "ClapTrap name: Unnamed_clap_name\n";

    std::cout << "\nActual whoAmI():\n";
    a.whoAmI();

    std::cout << "\n===== NAMED CONSTRUCTOR TEST =====\n";
    DiamondTrap b("Ruby");

    std::cout << "\nExpected whoAmI():\n";
    std::cout << "DiamondTrap name: Ruby\n";
    std::cout << "ClapTrap name: Ruby_clap_name\n";

    std::cout << "\nActual whoAmI():\n";
    b.whoAmI();

    std::cout << "\n===== ATTACK TEST =====\n";

    std::cout << "Expected:\n";
    std::cout << "ScavTrap Ruby_clap_name attacks target_dummy, causing 30 points of damage!\n";

    std::cout << "\nActual:\n";
    b.attack("target_dummy");

    std::cout << "\n===== ENERGY CONSUMPTION TEST =====\n";

    std::cout << "Expected: 50 attacks maximum\n";

    for (int i = 1; i < 53; i++)
    {
        std::cout << "Attack #" << i << ": ";
        b.attack("training_bot");
    }

    std::cout << "\nExpected after energy depletion:\n";
    std::cout << "No energy left to attack\n";

    std::cout << "\n===== COPY CONSTRUCTOR TEST =====\n";

    DiamondTrap c(b);

    std::cout << "Expected whoAmI():\n";
    std::cout << "DiamondTrap name: Ruby\n";
    std::cout << "ClapTrap name: Ruby_clap_name\n";

    std::cout << "\nActual whoAmI():\n";
    c.whoAmI();

    std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====\n";

    DiamondTrap d("Temp");

    std::cout << "Before assignment:\n";
    d.whoAmI();

    d = b;

    std::cout << "\nAfter assignment (expected Ruby):\n";
    d.whoAmI();

    std::cout << "\n===== MULTIPLE OBJECT TEST =====\n";

    DiamondTrap e("Alpha");
    DiamondTrap f("Beta");

    e.whoAmI();
    f.whoAmI();

    std::cout << "\n===== END OF PROGRAM =====\n";

    return 0;
}
