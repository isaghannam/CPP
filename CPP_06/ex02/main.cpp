/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:14:49 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/25 19:01:51 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
    int randomic = std::rand();
    randomic = randomic % 3;
    if (randomic == 0)
        return new A;
    else if (randomic == 1)
        return new B;
    else
        return new C;    
}

void identify(Base* p)
{
    Base *temp = dynamic_cast<A*>(p);
    if (temp != NULL)
    {
        std::cout << "Type is A!\n";
        return ;
    }
    temp = dynamic_cast<B*>(p);
    if (temp != NULL)
    {
        std::cout << "Type is B!\n";
        return ;
    }
    temp = dynamic_cast<C*>(p);
    if (temp != NULL)
    {
        std::cout << "Type is C!\n";
        return ;
    }
}

void identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "Type is A!\n";
        return ;
    }
    catch(const std::exception& e)
    {
        
    }
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "Type is B!\n";
        return ;
    }
    catch(const std::exception& e)
    {
        
    }
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "Type is C!\n";
        return ;
    }
    catch(const std::exception& e)
    {
        
    }
}

static void separator()
{
    std::cout << "---------------------------------\n";
}

int main()
{
    std::srand(std::time(NULL));

    Base* a = new A;
    identify(a);
    identify(*a);
    delete a;

    separator();

    Base* b = new B;
    identify(b);
    identify(*b);
    delete b;

    separator();

    Base* c = new C;
    identify(c);
    identify(*c);
    delete c;

    separator();
    
    std::cout << "===== BASIC SINGLE TEST =====\n";
    Base *single = generate();

    std::cout << "identify(Base*): ";
    identify(single);

    std::cout << "identify(Base&): ";
    identify(*single);

    delete single;

    separator();

    std::cout << "===== MULTIPLE RANDOM TESTS =====\n";

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Test #" << i + 1 << "\n";

        Base *obj = generate();

        std::cout << "Pointer version : ";
        identify(obj);

        std::cout << "Reference version: ";
        identify(*obj);

        delete obj;

        separator();
    }

    std::cout << "===== STRESS TEST (100 iterations) =====\n";

    for (int i = 0; i < 100; ++i)
    {
        Base *obj = generate();
        identify(obj);
        identify(*obj);
        delete obj;
    }

    std::cout << "Stress test completed.\n";

    return 0;
}