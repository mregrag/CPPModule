/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:36:01 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/28 14:30:04 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <iostream>
#include <limits>
#include <cfloat>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
    (void)rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    (void)rhs;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isChar(const std::string& str)
{
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	return (true);
    return (false);
}

bool ScalarConverter::isInt(const std::string& str)
{
    size_t i = 0;
    if (str[0] == '+' || str[0] == '-')
	i++;
    while (i < str.length())
    {
        if (!std::isdigit(str[i])) 
	    return (false);
        i++;
    }
    return (true);
}

bool ScalarConverter::isFloat(const std::string& str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
	return (true);
    if (str.length() < 2 || str[str.length() - 1] != 'f')
	return (false);
    
    std::string temp = str.substr(0, str.length() - 1);
    size_t i = 0;
    bool hasDecimal = false;
    
    if (temp[0] == '+' || temp[0] == '-') i++;
    while (i < temp.length())
    {
        if (temp[i] == '.')
	{
            if (hasDecimal)
		return (false);
            hasDecimal = true;
        }
        else if (!std::isdigit(temp[i]))
	    return (false);
        i++;
    }
    return (hasDecimal);
}

bool ScalarConverter::isDouble(const std::string& str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
	return (true);
    
    size_t i = 0;
    bool hasDecimal = false;
    
    if (str[0] == '+' || str[0] == '-') i++;
    while (i < str.length())
    {
        if (str[i] == '.')
	{
            if (hasDecimal)
		return (false);
            hasDecimal = true;
        }
        else if (!std::isdigit(str[i]))
	    return (false);
        i++;
    }
    return (hasDecimal);
}
void ScalarConverter::convertFromChar(std::string str)
{
    char value = str[0];

    std::cout << "char: '" << value << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(std::string str)
{
    long  value = std::atol(str.c_str());

    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    int intValue = static_cast<int>(value);
    if (intValue < 0 || intValue > 127)
        std::cout << "char: impossible" << std::endl;
    else if (intValue < 32 || intValue == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
    std::cout << "int: " << intValue << std::endl;
    std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;

    std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(std::string str)
{
    float value = std::atof(str.c_str());

    if (std::isnan(value))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    if (std::isinf(value))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
        return;
    }

    if (value >= 32 && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else if ((value >= 0 && value < 32) || value == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    long intVal = static_cast<long>(value);
    if (intVal > std::numeric_limits<int>::max() || value < (std::numeric_limits<int>::min()))
        std::cout << "int: impossible" << std::endl;
    else 
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}
void ScalarConverter::convertFromDouble(std::string str)
{
    double value = atof(str.c_str());  // Use atof to parse the string to a double.

    if (std::isnan(value))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    // Handle Infinity
    if (std::isinf(value))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
        return;
    }

    if (value >= 32 && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else if ((value >= 0 && value < 32) || value == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    // Handle int conversion with range check
    long intval = static_cast<long>(value);
    if (intval > std::numeric_limits<int>::max() || intval < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else 
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    // Handle float conversion
    float floatValue = static_cast<float>(value);
    if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << floatValue << "f" << std::endl;

    std::cout << "double: " << value << std::endl;
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
