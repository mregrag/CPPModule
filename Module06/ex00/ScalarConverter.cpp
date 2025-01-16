/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:36:01 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/16 00:15:42 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

/*ScalarConverter::ScalarConverter() {}*/
/*ScalarConverter::ScalarConverter(const ScalarConverter& other) {}*/
/*ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {*/
/*    return *this;*/
/*}*/
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& str) {
    if (str.size() != 3 || str[0] != '\'' || str[2] != '\'') return false;
    return true;
}

bool ScalarConverter::isInt(const std::string& str) {
    if (str.empty()) return false;
    char* end;
    long value = strtol(str.c_str(), &end, 10);
    if (end == str.c_str() + str.size() && value >= INT_MIN && value <= INT_MAX) {
        return true;
    }
    return false;
}

bool ScalarConverter::isFloat(const std::string& str) {
    if (str.empty() || str[str.size()-1] != 'f') return false;
    std::string num = str.substr(0, str.size()-1);
    if (num == "nan" || num == "inf" || num == "-inf") return true;
    char* end;
    /*float value = strtof(num.c_str(), &end);*/
    return end == num.c_str() + num.size();
}

bool ScalarConverter::isDouble(const std::string& str) {
    if (str.empty()) return false;
    if (str == "nan" || str == "inf" || str == "-inf") return true;
    char* end;
    double value = strtod(str.c_str(), &end);
    return end == str.c_str() + str.size();
}

void ScalarConverter::convertFromChar(char value) {
    std::cout << "char: '" << value << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromInt(int value) {
    std::cout << "char: ";
    if (value >= CHAR_MIN && value <= CHAR_MAX && isprint(value)) {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromFloat(float value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
    } else if (value < CHAR_MIN || value > CHAR_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
    } else if (value < INT_MIN || value > INT_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "+inff" << std::endl;
        } else {
            std::cout << "-inff" << std::endl;
        }
    } else {
        std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    }
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "+inf" << std::endl;
        } else {
            std::cout << "-inf" << std::endl;
        }
    } else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    }
}

void ScalarConverter::convertFromDouble(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
    } else if (value < CHAR_MIN || value > CHAR_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
    } else if (value < INT_MIN || value > INT_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "+inff" << std::endl;
        } else {
            std::cout << "-inff" << std::endl;
        }
    } else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    }
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "+inf" << std::endl;
        } else {
            std::cout << "-inf" << std::endl;
        }
    } else {
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    }
}

void ScalarConverter::convert(const std::string& str) {
    if (isChar(str)) {
        char value = str[1];
        convertFromChar(value);
    } else if (isInt(str)) {
        int value = std::strtol(str.c_str(), NULL, 10);
        convertFromInt(value);
    } else if (isFloat(str)) {
        float value = std::strtof(str.substr(0, str.size()-1).c_str(), NULL);
        convertFromFloat(value);
    } else if (isDouble(str)) {
        double value = std::strtod(str.c_str(), NULL);
        convertFromDouble(value);
    } else {
        std::cout << "Invalid input" << std::endl;
    }
}
