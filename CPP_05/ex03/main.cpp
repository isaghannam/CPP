/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:43:52 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/24 17:35:57 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

static void printResult(std::string testName, std::string expected, std::string obtained)
{
    std::cout << "==============================\n";
    std::cout << "TEST: " << testName << "\n";
    std::cout << "EXPECTED: " << expected << "\n";
    std::cout << "OBTAINED: " << obtained << "\n";
    std::cout << "==============================\n\n";
}

int main()
{
    Intern intern;
    AForm* form;

    std::cout << "\n===== TEST 1: ShrubberyCreationForm =====\n";
    form = intern.makeForm("ShrubberyCreationForm", "home");
    if (form)
    {
        printResult(
            "Create Shrubbery",
            "Intern creates ShrubberyCreationForm",
            "Intern creates " + form->getName()
        );
        delete form;
    }
    else
        printResult("Create Shrubbery", "Valid form pointer", "NULL");


    std::cout << "\n===== TEST 2: RobotomyRequestForm =====\n";
    form = intern.makeForm("RobotomyRequestForm", "Bender");
    if (form)
    {
        printResult(
            "Create Robotomy",
            "Intern creates RobotomyRequestForm",
            "Intern creates " + form->getName()
        );
        delete form;
    }
    else
        printResult("Create Robotomy", "Valid form pointer", "NULL");


    std::cout << "\n===== TEST 3: PresidentialPardonForm =====\n";
    form = intern.makeForm("PresidentialPardonForm", "Ford Prefect");
    if (form)
    {
        printResult(
            "Create Presidential",
            "Intern creates PresidentialPardonForm",
            "Intern creates " + form->getName()
        );
        delete form;
    }
    else
        printResult("Create Presidential", "Valid form pointer", "NULL");


    std::cout << "\n===== TEST 4: Invalid Form =====\n";
    form = intern.makeForm("coffee request", "Nobody");
    if (!form)
        printResult(
            "Invalid form",
            "Error message + NULL",
            "NULL returned"
        );
    else
    {
        printResult(
            "Invalid form",
            "NULL",
            "Form created unexpectedly"
        );
        delete form;
    }


    std::cout << "\n===== TEST 5: Multiple creations =====\n";
    AForm* f1 = intern.makeForm("ShrubberyCreationForm", "garden");
    AForm* f2 = intern.makeForm("RobotomyRequestForm", "Marvin");
    AForm* f3 = intern.makeForm("PresidentialPardonForm", "Arthur");

    std::cout << "EXPECTED: 3 forms created\n";
    std::cout << "OBTAINED: "
              << (f1 != NULL)
              << (f2 != NULL)
              << (f3 != NULL)
              << " (1 = success)\n";

    delete f1;
    delete f2;
    delete f3;

    std::cout << "\n===== END TESTS =====\n";
    return 0;
}