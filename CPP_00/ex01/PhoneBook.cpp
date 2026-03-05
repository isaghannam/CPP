/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:55:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/04 16:15:25 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook()
{
    oldest_index = 0;
    total_contacts = 0;
}

void PhoneBook::add_contact()
{
    std::string first_name;
    std::string surname;
    std::string nickname;
    std::string telephone;
    std::string darkest_secret;
    std::cout << "First name: ";
    std::getline(std::cin, first_name);
    std::cout << "Surname: ";
    std::getline(std::cin, surname);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Telephone: ";
    std::getline(std::cin, telephone);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkest_secret);
    
    if (total_contacts <= 7)
    {
        contacts[total_contacts] = Contact(total_contacts, first_name, surname, nickname, telephone, darkest_secret);
        total_contacts++;
    }
    else
    {
        contacts[oldest_index] = Contact(oldest_index, first_name, surname, nickname, telephone, darkest_secret);
        oldest_index++;
        oldest_index = oldest_index % 8;
    }
}

void PhoneBook::search()
{
    int index;
    std::string ind;
    std::cout << "     Index|First Name|   Surname|  Nickname\n";
    for (int i = 0; i < total_contacts; i++)
        contacts[i].print_contact_search();
    std::cout << "Insert contact index: ";
    std::getline(std::cin, ind);
    index = ind[0] - '0';
    if (ind.length() != 1 || index < 0 || index >= total_contacts)
    {
        std::cout << "Index not valid. Returning to main menu.\n";
        return ;
    }
    contacts[index].print_contact_complete();
}
