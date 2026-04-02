/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:54:35 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/02 14:22:29 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> data;
public:
    BitcoinExchange(std::string data);
    BitcoinExchange(const BitcoinExchange & other);
    BitcoinExchange & operator=(const BitcoinExchange & other);
    ~BitcoinExchange();
    class ErrorDublicatedDataInDatabaseException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class ErrorOpeningFileException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class ErrorInHeaderException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class ErrorInExchangeValueException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class ErrorBadDateException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class ErrorBadValueException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class ErrorNegativeValueException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class ErrorTooLargeValueException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class ErrorEmptyDataException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    void calculatePosition(std::string date, std::string qty);
    void processInput(std::string input_file);
};


bool isValidDate(std::string date);

#endif