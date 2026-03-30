/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:03:58 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/30 17:34:24 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <ctime>


void print_vector(std::vector<int> vec_int)
{
    for (size_t i = 0; i < vec_int.size(); i++)
        std::cout << vec_int.at(i) << " ";  
} 


int main()
{
    std::srand(std::time(NULL));
    {
        std::cout << "SIMPLE TEST WITH 0 NUMBERS LIMIT (expected: exceptions)\n";
        Span span_test(0);
        try
        {
            span_test.addNumber(1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << "LONGEST SPAN: " << span_test.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << "SHORTEST SPAN: " << span_test.shortestSpan() << "\n";
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << "\n\n";
        }        
    }
    {
        std::cout << "SIMPLE TEST WITH 1 NUMBERS LIMIT (expected: exceptions to longest and shortest span)\n";
        Span span_test(1);
        try
        {
            span_test.addNumber(1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << "LONGEST SPAN: " << span_test.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << "SHORTEST SPAN: " << span_test.shortestSpan() << "\n";
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << "\n\n";
        }        
    }
    {
        std::cout << "SIMPLE TEST WITH 5 NUMBERS LIMIT\n";
        Span span_test(5);
        span_test.addNumber(1);
        span_test.addNumber(2);
        span_test.addNumber(3);
        span_test.addNumber(4);
        span_test.addNumber(5);
        std::cout << "max size (expected: 5): " << span_test.getMaxSize() << std::endl;
        std::cout << "numbers vector (expected: 1 2 3 4 5): ";
        print_vector(span_test.getNumbers());
        std::cout << "\n";
        std::cout << "Add one more number (expected: exception thrown): \n";
        try
        {
            span_test.addNumber(6);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "LONGEST SPAN (expected: 4): " << span_test.longestSpan() << std::endl;
        std::cout << "SHORTEST SPAN (expected: 1): " << span_test.shortestSpan() << "\n\n";
    }

    {
        Span span_test(10);
        std::cout << "TEST TRYING TO INSERT A RANGE BIGGER THAN THE SPAN SUPPORTS (expected: exception)\n";
        std::list<int> list_test;
        for (size_t i = 0; i < 11; i++)
            list_test.push_back(i);
        try
        {
            span_test.addNumbers(list_test.begin(), list_test.end());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << "\n\n";
        }
    }

    {
        std::cout << "TEST WITH 10.001 consecutive elements (0-10.000) inserted with list iterators\n";
        Span span_test(10001);
        std::list<int> list_test;
        for (size_t i = 0; i < 10001; i++)
            list_test.push_back(i);
        span_test.addNumbers(list_test.begin(), list_test.end());
        std::cout << "LONGEST SPAN (expected: 10.000): " << span_test.longestSpan() << std::endl;
        std::cout << "SHORTEST SPAN (expected: 1): " << span_test.shortestSpan() << "\n\n";
    }

    {
        std::cout << "TEST WITH 20.000 random ints\n";
        Span span_test(20000);
        std::list<int> list_test;
        for (size_t i = 0; i < 20000; i++)
            list_test.push_back(rand());
        span_test.addNumbers(list_test.begin(), list_test.end());
        try
        {
            std::cout << "LONGEST SPAN: " << span_test.longestSpan() << std::endl;
            std::cout << "SHORTEST SPAN: " << span_test.shortestSpan() << "\n";
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }        
    }
}