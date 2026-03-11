/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:50:48 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/10 11:21:25 by ighannam         ###   ########.fr       */
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
        std::cout << "Type a VALID command (ADD, SEARCH OR EXIT):\n";
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cout << "EOF detected. Returning to main menu.\n";
            clearerr(stdin);
            std::cin.clear();
        }
        else if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search();
        else if (command == "EXIT")
            break;
        else
            std::cout << "\"" << command << "\"" << " is not valid command.\n";
    }
    return (0);    
}
