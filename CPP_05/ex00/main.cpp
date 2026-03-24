/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:03:42 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/24 10:06:27 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include "Bureaucrat.hpp"

static void separator(std::string title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("VALID CONSTRUCTION");
    try
    {
        Bureaucrat a("Alice", 42);
        std::cout << "Expected: Alice, bureaucrat grade 42\n";
        std::cout << "Obtained: " << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("INVALID CONSTRUCTION (GRADE TOO HIGH)");
    try
    {
        Bureaucrat b("Bob", 0);
        std::cout << "ERROR: exception should have been thrown\n";
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Expected: exception\n";
        std::cout << "Obtained: " << e.what() << std::endl;
    }

    separator("INVALID CONSTRUCTION (GRADE TOO LOW)");
    try
    {
        Bureaucrat c("Charlie", 151);
        std::cout << "ERROR: exception should have been thrown\n";
        std::cout << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Expected: exception\n";
        std::cout << "Obtained: " << e.what() << std::endl;
    }

    separator("INCREMENT NORMAL");
    try
    {
        Bureaucrat d("David", 10);
        d.incrementGrade();
        std::cout << "Expected grade: 9\n";
        std::cout << "Obtained: " << d.getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("DECREMENT NORMAL");
    try
    {
        Bureaucrat e("Eve", 10);
        e.decrementGrade();
        std::cout << "Expected grade: 11\n";
        std::cout << "Obtained: " << e.getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("INCREMENT OUT OF RANGE");
    try
    {
        Bureaucrat f("Frank", 1);
        f.incrementGrade();
        std::cout << "ERROR: exception should have been thrown\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Expected: exception\n";
        std::cout << "Obtained: " << e.what() << std::endl;
    }

    separator("DECREMENT OUT OF RANGE");
    try
    {
        Bureaucrat g("George", 150);
        g.decrementGrade();
        std::cout << "ERROR: exception should have been thrown\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Expected: exception\n";
        std::cout << "Obtained: " << e.what() << std::endl;
    }

    separator("COPY CONSTRUCTOR");
    try
    {
        Bureaucrat h("Henry", 25);
        Bureaucrat copy(h);

        std::cout << "Expected: Henry, bureaucrat grade 25\n";
        std::cout << "Obtained: " << copy << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("ASSIGNMENT OPERATOR");
    try
    {
        Bureaucrat i("Isaac", 30);
        Bureaucrat j("Julia", 100);

        j = i;

        std::cout << "Expected name: Julia (const, not copied)\n";
        std::cout << "Expected grade: 30\n";
        std::cout << "Obtained: " << j << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("GETTERS");
    try
    {
        Bureaucrat k("Kevin", 77);
        std::cout << "Expected name: Kevin\n";
        std::cout << "Obtained: " << k.getName() << std::endl;

        std::cout << "Expected grade: 77\n";
        std::cout << "Obtained: " << k.getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    separator("END OF TESTS");
    return 0;
}