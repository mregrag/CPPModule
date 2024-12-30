/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:36:01 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/30 00:20:42 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScalarConverter.cpp
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal)
{
    if (literal == "nan" || literal == "nanf")
    {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;

	return;
    }

    if (literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
    {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << (literal[0] == '+' ? "+" : "-") << "inff" << std::endl;
	std::cout << "double: " << (literal[0] == '+' ? "+" : "-") << "inf" << std::endl;

	return;
    }

    double value;
    if (isChar(literal))
	value = static_cast<double>(literal[1]);
    else
	value = std::atof(literal.c_str());

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

void ScalarConverter::printChar(double value) {
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
	std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value > 126)
	std::cout << "char: Non displayable" << std::endl;
    else
	std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value) {
    if (std::isnan(value) || std::isinf(value) || 
	    value > std::numeric_limits<int>::max() || 
	    value < std::numeric_limits<int>::min())
	std::cout << "int: impossible" << std::endl;
    else
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
    if (std::isnan(value))
	std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value)) {
	std::cout << "float: " << (value > 0 ? "+" : "-") << "inff" << std::endl;
    }
    else {
	std::cout << "float: " << static_cast<float>(value);
	if (static_cast<float>(value) == static_cast<int>(value))
	    std::cout << ".0";
	std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value) {
    if (std::isnan(value))
	std::cout << "double: nan" << std::endl;
    else if (std::isinf(value)) {
	std::cout << "double: " << (value > 0 ? "+" : "-") << "inf" << std::endl;
    }
    else {
	std::cout << "double: " << value;
	if (value == static_cast<int>(value))
	    std::cout << ".0";
	std::cout << std::endl;
    }
}
