/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ighannam <ighannam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:54:31 by ighannam          #+#    #+#             */
/*   Updated: 2026/04/02 14:36:39 by ighannam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string data)
{
    std::ifstream database(data.c_str());
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
        if ((map_data.insert(pair_data)).second == false)
        {
            std::cerr << pair_data.first << " ";
            throw ErrorDublicatedDataInDatabaseException();
        }       
    }
    if (map_data.empty())
        throw ErrorEmptyDataException();
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

const char *BitcoinExchange::ErrorBadValueException::what() const throw()
{
    return ("Error: not a valid input number");
}

const char *BitcoinExchange::ErrorNegativeValueException::what() const throw()
{
    return ("Error: not a positive number.");
}

const char *BitcoinExchange::ErrorTooLargeValueException::what() const throw()
{
    return ("Error: too large a number.");
}

const char *BitcoinExchange::ErrorEmptyDataException::what() const throw()
{
    return ("Error: no exchange data");
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
    std::ifstream input(input_file.c_str());
    if (!input.is_open())
        throw ErrorOpeningFileException();
    std::string line;
    std::string input_date;
    std::string qty;
    std::getline(input, input_date, '|');
    if (input_date != "date ")
        throw ErrorInHeaderException();
    std::getline(input, qty);
    if (qty != " value")
        throw ErrorInHeaderException();
    while (std::getline(input, line))
    {
        if (line.length() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        input_date = line.substr(0, 10);
        qty = line.substr(13, line.length() - 13);
        try
        {
            calculatePosition(input_date, qty);
        }
        catch(const BitcoinExchange::ErrorBadDateException& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const BitcoinExchange::ErrorBadValueException& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const BitcoinExchange::ErrorNegativeValueException& e)
        {
            std::cerr << e.what() << '\n';
        }
        catch(const BitcoinExchange::ErrorTooLargeValueException& e)
        {
            std::cerr << e.what() << '\n';
        }        
    }
}

void BitcoinExchange::calculatePosition(std::string date, std::string qty)
{
    std::map<std::string, double>::iterator price;
    double value;
    char *end;
    if (!isValidDate(date))
        throw ErrorBadDateException();
    value = std::strtod(qty.c_str(), &end);
    if (!(end[0] == '\0'))
        throw ErrorBadValueException();
    if (value > 1000)
        throw ErrorTooLargeValueException();
    if (value < 0)
        throw ErrorNegativeValueException();
    price = (data.lower_bound(date));
    if (price == data.begin() && (*price).first != date)
    {
        std::cerr << "Error: no data available for this date or before it.\n";
        return;
    }
    else if (price == data.end() || (*price).first != date)
        --price;
    std::cout << date << " => " << value << " = " << (*price).second * value << std::endl;
}
