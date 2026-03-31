/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:54:31 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/31 15:34:48 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::map<std::string, float> data)
    : data(data)
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other)
    : data(other.data)
{
    
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & other)
{
    if (this != &other)
    {
        data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    
}

float BitcoinExchange::findExchangeRate(std::string date)
{
    
}

float BitcoinExchange::calculatePosition(std::string date, int value)
{
    
}