/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:40:32 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/22 21:24:14 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _date(""), _value(0)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) : _database(rhs._database), _date(rhs._date), _value(rhs._value)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) 
{
	if (this != &rhs)
	{
		_database = rhs._database;
		_date = rhs._date;
		_value = rhs._value;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string BitcoinExchange::trim(const std::string& s)
{
	size_t start = s.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ("");
	size_t end = s.find_last_not_of(" \t");
	return (s.substr(start, end - start + 1));
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int BitcoinExchange::getDaysInMonth(int month, int year) const
{
	if (month == 2)
		return isLeapYear(year) ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return (30);
	else
		return (31);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (size_t i = 0; i < date.length(); i++)
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return (false);

	int year, month, day;
	std::istringstream yearStream(date.substr(0, 4));
	std::istringstream monthStream(date.substr(5, 2));
	std::istringstream dayStream(date.substr(8, 2));

	if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day))
		return (false);
	if (year < 1 || month < 1 || month > 12 || day < 1)
		return (false);

	if (day > getDaysInMonth(month, year))
		return (false);
	return (true);
}

void BitcoinExchange::checkValue(const std::string& valueStr)
{
    std::istringstream iss(valueStr);

    if (!(iss >> _value) || !iss.eof())
        throw std::runtime_error("Error: not a valid number.");

    if (_value < 0)
        throw std::runtime_error("Error: not a positive number.");

    if (_value > 1000)
        throw std::runtime_error("Error: too large a number.");
}


std::string BitcoinExchange::findClosestLowerDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
	if (it == _database.begin() && it->first != date)
		throw std::runtime_error("Error: no valid rate found for date " + _date);
	if (it == _database.end() || it->first != date)
		--it;
	return (it->first);
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	if (!std::getline(file, line) || line != "date,exchange_rate")
	{
		file.close();
		throw std::runtime_error("Please provide a valid data file!");
	}
	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			file.close();
			throw std::runtime_error("Error: invalid line format");
		}
		std::string date = trim(line.substr(0, pos));
		std::string rateStr = trim(line.substr(pos + 1));
		if (!isValidDate(date))
		{
			file.close();
			throw std::runtime_error("Error: invalid date" + date);
		}
		double rate;
		std::istringstream iss(rateStr);
		if (!(iss >> rate) || !iss.eof() || rate < 0)
		{
			file.close();
			throw std::runtime_error("Error: invalid rate" + rateStr);
		}
		_database[date] = rate;
	}
	file.close();
}

void BitcoinExchange::loadInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	if (!std::getline(file, line) || line != "date | value")
	{
		file.close();
		throw std::runtime_error("Please provide a valid input file!");
	}

	while (std::getline(file, line))
	{
		try
		{
			size_t pos = line.find('|');
			if (pos == std::string::npos)
				throw std::runtime_error("Error: bad input => " + line);

			_date = trim(line.substr(0, pos));
			if (!isValidDate(_date))
				throw std::runtime_error("Error: bad input => " + _date);

			std::string valueStr = trim(line.substr(pos + 1));
			checkValue(valueStr);

			std::string useDate = findClosestLowerDate(_date);

			std::cout << _date << " => " << _value << " = " << _value * _database[useDate] << std::endl;
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
}
