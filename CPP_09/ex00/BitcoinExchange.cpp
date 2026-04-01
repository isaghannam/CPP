/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:54:31 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/01 19:29:56 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::map<std::string, double> data)
    : data(data)
{
    
}

BitcoinExchange::BitcoinExchange(std::string data)
{
    std::ifstream database("data.csv");
    if (!database.is_open())
        throw ErrorOpeningFileException();
    std::string date;
    std::string exchange_rate;
    std::map<std::string, double> map_data;
    std::pair<std::string, double> pair_data;
    char *end;
    double value;
    std::map<std::string, double>::iterator price;
    std::getline(database, date, ',');
    if (date != "date")
        throw ErrorInHeaderException();
    std::getline(database, exchange_rate);
    if (exchange_rate != "exchange_rate")
        throw ErrorInHeaderException();
    while (std::getline(database, date, ','))
    {
        if (!isValidDate(date))
            throw ErrorBadDateException();
        pair_data.first = date;
        std::getline(database, exchange_rate);
        value = std::strtod(exchange_rate.c_str(), &end);
        if (!((end[0] == 'f' && end[1] == '\0') || end[0] == '\0') )
        {
            std::cerr << "Exchange rate: " << exchange_rate << " ";
            throw ErrorInExchangeValueException();
        }
        pair_data.second = value;
        if ((*map_data.insert(map_data.end(), pair_data)).second == false)
        {
            std::cerr << "Duplicatede key in database: " << pair_data.first << " ";
            throw ErrorDublicatedDataInDatabaseException();
        }       
    }
    this->data = map_data;
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

const char *BitcoinExchange::ErrorDublicatedDataInDatabaseException::what() const throw()
{
    return "Error: duplicated dates in database";
}

const char *BitcoinExchange::ErrorOpeningFileException::what() const throw()
{
    return ("Error: failed to open file");
}

const char *BitcoinExchange::ErrorInHeaderException::what() const throw()
{
    return ("Error in header");
}

const char *BitcoinExchange::ErrorInExchangeValueException::what() const throw()
{
    return ("Exchange value not valid in database");
}

const char *BitcoinExchange::ErrorBadDateException::what() const throw()
{
    return ("Date is not valid");
}

bool isValidDate(std::string date)
{
    char *end;
    std::string year;
    std::string month;
    std::string day;
    int year_number;
    int month_number;
    int day_number;
    if (date.length() != 10)
        return false;
    for (size_t i = 0; i < 10; i++)
    {
        if (!std::isdigit(date[i]) && !(date[i] == '-'))
            return false;
    }
    if (!(date[4] == '-') || !(date[7] == '-'))
        return false;
    year = date.substr(0, 4);
    month = date.substr(5, 2);
    day = date.substr(8, 2);
    year_number = static_cast<int>(std::strtod(year.c_str(), &end));
    month_number = static_cast<int>(std::strtod(month.c_str(), &end));
    day_number = static_cast<int>(std::strtod(day.c_str(), &end));
    struct std::tm tm;
    memset(&tm, 0, sizeof(tm));
    tm.tm_isdst = -1;
    tm.tm_year = year_number - 1900;
    tm.tm_mon = month_number - 1;
    tm.tm_mday = day_number;
    std::time_t t = std::mktime(&tm);
    if (t == -1)
        return false;
    std::tm local = *std::localtime(&t);
    if (local.tm_year != (year_number - 1900) || local.tm_mon != (month_number - 1)
        || local.tm_mday != (day_number))
        return false;
    return true;
}

void BitcoinExchange::processInput(std::string input_file)
{
    std::ifstream input(input_file);
    if (!input.is_open())
        throw ErrorOpeningFileException();
    std::string line;
    std::string input_date;
    std::string qty;
    std::getline(input, input_date, '|');
    if (input_date != "date ")
        throw ErrorInHeaderException();
    std::getline(input, qty);
    if (qty != "value")
        throw ErrorInHeaderException();
    while (std::getline(input, line))
    {
        if (line.length() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
        {
            std::cout << "Error in line: " << line << std::endl;
            continue;
        }
        input_date = line.substr(0, 10);
        qty = line.substr(13, line.length() - 13);
        try
        {
            calculatePosition(input_date, qty);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
    }
}

void BitcoinExchange::calculatePosition(std::string date, std::string qty)
{
    std::map<std::string, double>::iterator price;
    int value;
    char *end;
    if (!isValidDate(date))
    {
        throw ErrorBadDateException();
    }
    
    value = static_cast<int>(std::strtod(qty.c_str(), &end));
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