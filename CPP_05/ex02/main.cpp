/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:43:52 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/24 16:30:31 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

#define SEP std::cout << "\n--------------------------------------------\n";

int main()
{
    std::srand(std::time(NULL));

    SEP
    std::cout << "TEST 1 - ShrubberyCreationForm success\n";
    std::cout << "EXPECTED: file created + execution success\n";

    try
    {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm form("home");

        bob.signForm(form);
        bob.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    SEP
    std::cout << "TEST 2 - Execute without signing\n";
    std::cout << "EXPECTED: execution should fail (form not signed)\n";

    try
    {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm form("garden");

        bob.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    SEP
    std::cout << "TEST 3 - Signing with low grade\n";
    std::cout << "EXPECTED: signing should fail\n";

    try
    {
        Bureaucrat low("Low", 150);
        ShrubberyCreationForm form("park");

        low.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    SEP
    std::cout << "TEST 4 - Execute with low grade\n";
    std::cout << "EXPECTED: execution should fail\n";

    try
    {
        Bureaucrat signer("Signer", 1);
        Bureaucrat executor("Executor", 150);

        ShrubberyCreationForm form("yard");

        signer.signForm(form);
        executor.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    SEP
    std::cout << "TEST 5 - Robotomy multiple attempts\n";
    std::cout << "EXPECTED: ~50% success\n";

    try
    {
        Bureaucrat bob("Bob", 1);
        RobotomyRequestForm form("Bender");

        bob.signForm(form);

        for (int i = 0; i < 5; i++)
        {
            std::cout << "Attempt " << i + 1 << std::endl;
            bob.executeForm(form);
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    SEP
    std::cout << "TEST 6 - Presidential Pardon\n";
    std::cout << "EXPECTED: pardon message\n";

    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm form("Arthur Dent");

        president.signForm(form);
        president.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    SEP
    std::cout << "TEST 7 - Grades edge cases\n";
    std::cout << "EXPECTED: signing ok but execution fail\n";

    try
    {
        Bureaucrat signer("Signer", 72);
        Bureaucrat executor("Executor", 46);

        RobotomyRequestForm form("Marvin");

        signer.signForm(form);
        executor.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    SEP
    std::cout << "ALL TESTS FINISHED\n";
}