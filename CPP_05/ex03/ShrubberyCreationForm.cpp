/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:05:42 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/24 16:22:22 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("Default target")
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target)
{
    
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

const char *ShrubberyCreationForm::ProblemWithFileExcepetion::what() const throw()
{
    return ("Error creating or opening output file!");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    throw_execute_exceptions(executor.getGrade());
    std::string file_name = target + "_shrubbery";
    std::ofstream file(file_name.c_str());
    if (!file.is_open())
        throw ProblemWithFileExcepetion();
    for (int i = 0; i < 3; i++)
    {
        file << "   ^   \n";
        file << "  ^^^  \n";
        file << " ^^^^^ \n";
        file << "   |   \n\n";
    }
}
