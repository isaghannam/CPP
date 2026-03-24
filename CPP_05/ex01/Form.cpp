/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:47:08 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/24 14:01:38 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int Form::throw_grade_exceptions(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    return grade;
}

Form::Form()
    :name("Default Form Name"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute)
    :name(name), isSigned(false), gradeToSign(throw_grade_exceptions(gradeToSign)), gradeToExecute(throw_grade_exceptions(gradeToExecute))
{
 
}

Form::Form(const Form& other)
    :name(other.getName()), isSigned(other.getIsSigned()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute())
{
    
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->isSigned = other.getIsSigned();
    }
    return *this;
}

Form::~Form()
{
    
}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (gradeToSign < bureaucrat.getGrade())
        throw GradeTooLowException();
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form& obj)
{
    os << obj.getName() << ", form. Signed: " << std::boolalpha 
        << obj.getIsSigned() << ". Grade to Sign: " 
        << obj.getGradeToSign() << ". Grade to Execute: " 
        << obj.getGradeToExecute() << ".\n";
    return os;
}