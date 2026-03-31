/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:54:27 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/31 17:26:31 by ighannam         ###   ########.fr       */
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
    
    std::ifstream database("data.csv");
    if (!database.is_open())
    {
        std::cerr << "Error: failed to open data file.\n";
        return 1;
    }
    std::string date;
    std::string exchange_rate;
    std::getline(database, date, ',');
    if (date != "date")
    {
        std::cerr << "Error in database\n";
        return 1;
    }
    std::getline(database, exchange_rate);
    if (exchange_rate != "exchange_rate")
    {
        std::cerr << "Error in database\n";
        return 1;
    }
    while (std::getline(database, date, ','))
    {
        
    }
    
    
    return 0;
}