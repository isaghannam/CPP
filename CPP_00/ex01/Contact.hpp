/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:22:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/10 11:17:12 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdio>

class Contact
{
    private:
        int index;
        std::string first_name;
        std::string surname;
        std::string nickname;
        std::string telephone;
        std::string darkest_secret;
    public:
        Contact();
        Contact(int index, std::string first_name, std::string surname, std::string nickname, std::string telephone, std::string darkest_secret);
        void print_contact_search();
        void print_contact_complete();
};


#endif