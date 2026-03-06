/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:06:26 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/05 22:10:35 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl h;
    if (argc != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        return (1);
    }
    std::string param = argv[1];
    int i = -1;
    std::string values[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (++i < 4)
    {
        if (param == values[i])
            break;
    }
    if (i == 4)
    {
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        return (1);
    }
    switch (i)
    {
    case 0:
        h.complain("DEBUG");
        // fall through
    case 1:
        h.complain("INFO");
        // fall through
    case 2:
        h.complain("WARNING");
        // fall through
    case 3:
        h.complain("ERROR");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        break;
    }
    return (0);
}