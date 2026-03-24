/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:47:41 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/24 17:37:26 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
    
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    
}

AForm* Intern::makeShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}
AForm* Intern::makeRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}
AForm* Intern::makePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
    std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm *(Intern::*f[3])(std::string) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == form_name)
        {
            AForm* new_form = (this->*f[i])(target);
            std::cout << "Intern creates " << form_name << std::endl;
            return new_form;
        }
    }
    std::cerr << "Error: Intern could not create form " << form_name << std::endl;
    return NULL;
}
