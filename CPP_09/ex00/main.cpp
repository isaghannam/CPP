/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:54:27 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/01 18:59:52 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: wrong number of args. Usage: ./btc <input_file>\n";
        return 1;
    }
    try
    {
        BitcoinExchange btc_database("data.csv");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    std::ifstream input(argv[1]);
    if (!input.is_open())
    {
        std::cerr << "Error: input file could not be opened.\n";
        return 1;
    }
    std::string line;
    std::string input_date;
    std::string qty;
    std::getline(input, input_date, '|');
    if (input_date != "date ")
    {
        std::cerr << "Error: input must have correct header.\n";
        return 1;
    }
    std::getline(input, qty);
    if (qty != "value")
    {
        std::cerr << "Error: input must have correct header.\n";
        return 1;
    }
    while (std::getline(input, line))
    {
        if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
        {
            std::cout << "Error in line: " << line << std::endl;
            continue;
        }
        input_date = line.substr(0, 10);
        qty = line.substr(13, line.length() - 13);
        try
        {
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        value = std::strtod(qty.c_str(), &end);
        if (!(end[0] == '\0'))
        {
            std::cerr << "Error: bad value input => " << qty << std::endl;
            continue;
        }
        //if value is wrong print error & continue
        price = (map_data.lower_bound(input_date));
        if (price == map_data.end() || (*price).first != input_date)
            --price;
        else if (price == map_data.begin())
        {
            std::cerr << "Error: no data available for this date or before it.\n";
            continue;
        }
        std::cout << input_date << " => " << value << " = " << (*price).second * value;
    }
    
    
    return 0;
}

