/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:36:01 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/08 16:55:36 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isChar(const std::string& str)
{
    if (str.empty())
	return (false);
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	return (true);
    return (false);
}

bool ScalarConverter::isInt(const std::string& str)
{
    if (str.empty())
	return (false);
    for (size_t i = 0; i < str.length(); ++i)
    {
	if ((i == 0 && (str[i] == '-' || str[i] == '+')) || std::isdigit(str[i]))
	    continue;
	return (false);
    }
    return (true);
}

bool ScalarConverter::isFloat(const std::string& str)
{
    if (str.empty() || str[str.length() - 1] != 'f')
	return (false);
    int dotCount = 0;
    bool hasDigits = false;

    if (str == "nanf" || str == "+inff" || str == "-inff")
	return (true);

    for (size_t i = 0; i < str.length() - 1; ++i)
    {
	if (i == 0 && (str[i] == '-' || str[i] == '+'))
	    continue;
	if (str[i] == '.')
	    dotCount++;
	else if (!std::isdigit(str[i]))
	    return (false);
	else
	    hasDigits = true;
    }
    return (hasDigits && dotCount == 1);
}

bool ScalarConverter::isDouble(const std::string& str)
{
    if (str.empty())
	return false;
    if (str == "nan" || str == "+inf" || str == "-inf")
	return (true);
    int dotCount = 0;
    bool hasDigits = false;
    for (size_t i = 0; i < str.length(); ++i)
    {
	if (i == 0 && (str[i] == '-' || str[i] == '+'))
	    continue;
	if (str[i] == '.')
	    dotCount++;
	else if (!std::isdigit(str[i]))
	    return(false);
	else
	    hasDigits = true;
    }
    return (hasDigits && dotCount == 1);
}

void ScalarConverter::convertFromChar(const std::string& str)
{
    char value = str[0];
    std::cout << "char: '" << value << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& str)
{
    long value = std::atol(str.c_str());
    if (value < INT_MIN || value > INT_MAX)
    {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	return;
    }
    if (value < 0 || value > 127)
	std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value == 127)
	std::cout << "char: Non displayable" << std::endl;
    else
	std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& str)
{
    float value = static_cast<float>(std::atof(str.c_str()));

    std::cout << static_cast<int>(value) << std::endl;
    if (static_cast<int>(value) < 0 || static_cast<int>(value) > 127)
	std::cout << "char: impossible" << std::endl;
    else if (static_cast<int>(value) < 32 || static_cast<int>(value) == 127)
	std::cout << "char: Non displayable" << std::endl;
    else
	std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    if (static_cast<long>(value) < INT_MIN || static_cast<long>(value) > INT_MAX)
	std::cout << "int: impossible" << std::endl;
    else
	std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& str)
{
    double value = std::atof(str.c_str());

    if (static_cast<int>(value) < 0 || static_cast<int>(value) > 127)
	std::cout << "char: impossible" << std::endl;
    else if (static_cast<int>(value) < 32 || static_cast<int>(value) == 127)
	std::cout << "char: Non displayable" << std::endl;
    else
	std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    if (static_cast<long>(value) < INT_MIN || static_cast<long>(value) > INT_MAX)
	std::cout << "int: impossible" << std::endl;
    else
	std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(const std::string str)
{
    if (isChar(str))
	convertFromChar(str);
    else if (isInt(str))
	convertFromInt(str);
    else if (isFloat(str))
	convertFromFloat(str);
    else if (isDouble(str))
	convertFromDouble(str);
    else
	std::cout << "Invalid input" << std::endl;
}
