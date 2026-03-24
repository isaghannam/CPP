/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:43:52 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/24 16:04:04 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void separator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("VALID FORM CONSTRUCTION");
    try
    {
        Form f("Tax Form", 50, 25);
        std::cout << "Expected: name=Tax Form, signed=0, signGrade=50, execGrade=25\n";
        std::cout << "Obtained: " << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("INVALID FORM (GRADE TOO HIGH)");
    try
    {
        Form f("Invalid High", 0, 25);
        std::cout << "ERROR: exception should have been thrown\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Expected: exception\n";
        std::cout << "Obtained: " << e.what() << std::endl;
    }

    separator("INVALID FORM (GRADE TOO LOW)");
    try
    {
        Form f("Invalid Low", 50, 151);
        std::cout << "ERROR: exception should have been thrown\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Expected: exception\n";
        std::cout << "Obtained: " << e.what() << std::endl;
    }

    separator("SIGN SUCCESS");
    try
    {
        Bureaucrat b("Alice", 10);
        Form f("Permit", 20, 5);

        b.signForm(f);

        std::cout << "Expected: signed = 1\n";
        std::cout << "Obtained: " << f.getIsSigned() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("SIGN FAILURE (GRADE TOO LOW)");
    try
    {
        Bureaucrat b("Bob", 100);
        Form f("Top Secret", 50, 10);

        b.signForm(f);

        std::cout << "Expected: signed = 0\n";
        std::cout << "Obtained: " << f.getIsSigned() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("SIGN EXACT BORDER");
    try
    {
        Bureaucrat b("Charlie", 50);
        Form f("Border Case", 50, 25);

        b.signForm(f);

        std::cout << "Expected: signed = 1\n";
        std::cout << "Obtained: " << f.getIsSigned() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("ALREADY SIGNED");
    try
    {
        Bureaucrat b("David", 10);
        Form f("Duplicate", 20, 5);

        b.signForm(f);
        b.signForm(f);

        std::cout << "Expected: signed = 1\n";
        std::cout << "Obtained: " << f.getIsSigned() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("OPERATOR << TEST");
    try
    {
        Bureaucrat b("Eva", 5);
        Form f("Print Test", 10, 5);

        std::cout << "Expected: formatted form output\n";
        std::cout << "Obtained: " << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("GETTERS TEST");
    try
    {
        Form f("Getter", 42, 21);

        std::cout << "Expected name: Getter\n";
        std::cout << "Obtained: " << f.getName() << std::endl;

        std::cout << "Expected signed: 0\n";
        std::cout << "Obtained: " << f.getIsSigned() << std::endl;

        std::cout << "Expected sign grade: 42\n";
        std::cout << "Obtained: " << f.getGradeToSign() << std::endl;

        std::cout << "Expected exec grade: 21\n";
        std::cout << "Obtained: " << f.getGradeToExecute() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("END OF TESTS");
}