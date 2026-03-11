/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:55:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/10 18:36:24 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool verify_all_digits(std::string str);

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
	std::cout << "First name: \n";
	std::getline(std::cin, first_name);
    if (std::cin.eof() || first_name.length() == 0)
    {
		std::cout << "EOF detected or empty field. Returning to main menu.\n";
		clearerr(stdin);
		std::cin.clear();
        return ;
    }
	std::cout << "Last name: \n";
	std::getline(std::cin, surname);
    if (std::cin.eof() || surname.length() == 0)
    {
		std::cout << "EOF detected or empty field. Returning to main menu.\n";
		clearerr(stdin);
		std::cin.clear();
        return ;
    }
	std::cout << "Nickname: \n";
	std::getline(std::cin, nickname);
    if (std::cin.eof() || nickname.length() == 0)
    {
		std::cout << "EOF detected or empty field. Returning to main menu.\n";
		clearerr(stdin);
		std::cin.clear();
        return ;
    }
	std::cout << "Telephone: \n";
	std::getline(std::cin, telephone);
    if (std::cin.eof() || telephone.length() == 0 || !verify_all_digits(telephone))
    {
		std::cout << "EOF detected, empty field or telephone with non-numeric. Returning to main menu.\n";
		clearerr(stdin);
		std::cin.clear();
        return ;
    }
	std::cout << "Darkest secret: \n";
	std::getline(std::cin, darkest_secret);
    if (std::cin.eof() || darkest_secret.length() == 0)
    {
		std::cout << "EOF detected or empty field. Returning to main menu.\n";
		clearerr(stdin);
		std::cin.clear();
        return ;
    }
	if (total_contacts <= 7)
	{
		contacts[total_contacts] = Contact(total_contacts, first_name, surname,
				nickname, telephone, darkest_secret);
		total_contacts++;
	}
	else
	{
		contacts[oldest_index] = Contact(oldest_index, first_name, surname,
				nickname, telephone, darkest_secret);
		oldest_index++;
		oldest_index = oldest_index % 8;
	}
}

bool verify_all_digits(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

void PhoneBook::search()
{
	int	index;

	std::string ind;
	std::cout << "     Index|First Name| Last name|  Nickname\n";
	for (int i = 0; i < total_contacts; i++)
		contacts[i].print_contact_search();
	std::cout << "Insert contact index: \n";
	std::getline(std::cin, ind);
    if (std::cin.eof())
    {
		std::cout << "EOF detected. Returning to main menu.\n";
		clearerr(stdin);
		std::cin.clear();
        return ;
    }
	index = (ind[0] - 1) - '0';
	if (ind.length() != 1 || index < 0 || index >= total_contacts)
	{
		std::cout << "Index not valid. Returning to main menu.\n";
		return ;
	}
	contacts[index].print_contact_complete();
}
