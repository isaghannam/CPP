/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:54:35 by ighannam          #+#    #+#             */
/*   Updated: 2026/03/31 15:33:41 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
private:
    std::map<std::string, float> data;
public:
    BitcoinExchange(std::map<std::string, float> data);
    BitcoinExchange(const BitcoinExchange & other);
    BitcoinExchange & operator=(const BitcoinExchange & other);
    ~BitcoinExchange();
    float findExchangeRate(std::string date);
    float calculatePosition(std::string date, int value);
};



#endif