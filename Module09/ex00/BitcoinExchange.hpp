/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:41:25 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/08 20:43:37 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _database;
		std::string _date;
		double _value;

		std::string trim(const std::string& s);
		bool isValidDate(const std::string& date) const;
		void checkValue(const std::string& valueStr);
		bool isLeapYear(int year) const;
		int getDaysInMonth(int month, int year) const;
		std::string findClosestLowerDate(const std::string& date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadDatabase(const std::string& filename);
		void loadInputFile(const std::string& filename);
};

#endif
