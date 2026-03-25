/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 09:30:38 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/25 15:28:05 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    
}

void ScalarConverter::convertChar(double value)
{
    int value_char = (int)value;
    if ((value_char >= 0 && value_char <= 31) || value_char == 127)
        std::cout << "char: Non displayable\n";
    else if (value_char > 127 || value_char < 0 || std::isnan(value) || std::isinf(value))
        std::cout << "char: impossible\n";
    else
        std::cout << "char: '" << static_cast<char>(value_char) << "'\n"; 
    
}

void ScalarConverter::convertInt(double value)
{
    if (value > INT_MAX || value < INT_MIN || std::isnan(value) || std::isinf(value))
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::convertFloat(double value)
{
    if (std::isnan(value) || std::isinf(value))
        std::cout << "float: " << static_cast<float>(value) << "f\n";
    else if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
        std::cout << "float: impossible\n";
    else
    {
        if (value == static_cast<int>(value))
            std::cout << "float: " << (float)value << ".0f\n";
        else
            std::cout << "float: " << (float)value << "f\n";
    }
}

void ScalarConverter::convertDouble(double value)
{
    if (value == static_cast<int>(value))
        std::cout << "double: " << value << ".0\n";
    else
        std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string& number)
{
    char *end;
    double value; 
    if (number.length() == 1 && !std::isdigit(number[0]))
        value = static_cast<int>(number[0]);
    else
    {
        value = std::strtod(number.c_str(), &end);
        if (!((end[0] == 'f' && end[1] == '\0') || end[0] == '\0') )
        {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return ;
        }
    }   
    convertChar(value);
    convertInt(value);
    convertFloat(value);
    convertDouble(value);
}
