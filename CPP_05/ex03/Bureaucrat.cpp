/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:40:58 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/24 16:41:04 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

void Bureaucrat::throw_grade_exceptions(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat()
    : name("Default Bureaucrat Name"), grade(150)
{
    
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name(name)
{
    throw_grade_exceptions(grade);
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.getName()), grade(other.getGrade())
{
    
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    throw_grade_exceptions(grade - 1);
    grade--;
}

void Bureaucrat::decrementGrade()
{
    throw_grade_exceptions(grade + 1);
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't sign " << form.getName() 
            << " because " << e.what() << ".\n";
    } 
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << this->getName() << " couldn't execute " << form.getName() 
            << " because " << e.what() << ".\n";
    } 
}