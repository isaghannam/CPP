/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:50:48 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/09 16:21:01 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;
    std::cout << "Welcome to your amazing phonebook!\n";
    while (1)
    {
        std::cout << "Type a VALID command (ADD, SEARCH OR EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search();
        else if (command == "EXIT")
            break;
        else if (std::cin.eof())
            break;
        else
            std::cout << "\"" << command << "\"" << " is not valid command.\n";
    }
    return (0);    
}
