/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:22:16 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/10 18:36:42 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static void print_truncate(std::string &str);

Contact::Contact(int index, std::string first_name, std::string surname, std::string nickname, std::string telephone, std::string darkest_secret)
{
    this->index = index + 1;
    this->first_name = first_name;
    this->surname = surname;
    this->nickname = nickname;
    this->telephone = telephone;
    this->darkest_secret = darkest_secret;
}

Contact::Contact()
{
    
}

void Contact::print_contact_search()
{
    std::cout << "         " << index << "|";
    print_truncate(first_name);
    std::cout << "|";
    print_truncate(surname);
    std::cout << "|";
    print_truncate(nickname);
    std::cout << std::endl;
}

void Contact::print_contact_complete()
{
    std::cout << "INDEX: " << index << std::endl;
    std::cout << "FIRST NAME: " << first_name << std::endl;
    std::cout << "SURNAME: " << surname << std::endl;
    std::cout << "NICKNAME: " << nickname << std::endl;
    std::cout << "TELEPHONE: " << telephone << std::endl;
    std::cout << "DARKEST SECRET: " << darkest_secret << std::endl;
}

static void print_truncate(std::string &str)
{
    for (int i = 0; i < (10 - (int)str.length()) && (10 - str.length()) > 0; i++)
        std::cout << " ";    
    for (size_t i = 0; i < 9 && i < str.length(); i++)
        std::cout << str[i];
    if (str.length() == 10)
        std::cout << str[9];
    else if (str.length() > 10)
        std::cout << ".";
}
