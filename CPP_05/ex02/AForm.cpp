/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:47:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/24 16:36:58 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

int AForm::throw_grade_exceptions(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    return grade;
}

void AForm::throw_execute_exceptions(int grade) const
{
    if (!this->getIsSigned())
        throw NotSignedException();
    if (grade > this->getGradeToExecute())
        throw GradeTooLowException();
}

AForm::AForm()
    :name("Default Form Name"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    
}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute)
    :name(name), isSigned(false), gradeToSign(throw_grade_exceptions(gradeToSign)), gradeToExecute(throw_grade_exceptions(gradeToExecute))
{
 
}

AForm::AForm(const AForm& other)
    :name(other.getName()), isSigned(other.getIsSigned()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute())
{
    
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->isSigned = other.getIsSigned();
    }
    return *this;
}

AForm::~AForm()
{
    
}

const std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char *AForm::NotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (gradeToSign < bureaucrat.getGrade())
        throw GradeTooLowException();
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm& obj)
{
    os << obj.getName() << ", form. Signed: " << std::boolalpha 
        << obj.getIsSigned() << ". Grade to Sign: " 
        << obj.getGradeToSign() << ". Grade to Execute: " 
        << obj.getGradeToExecute() << ".\n";
    return os;
}