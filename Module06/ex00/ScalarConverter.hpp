/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:36:11 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/27 22:18:36 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
    private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& rhs);
	ScalarConverter& operator=(const ScalarConverter& rhs);

	static bool isChar(const std::string& str);
	static bool isInt(const std::string& str);
	static bool isFloat(const std::string& str);
	static bool isDouble(const std::string& str);

	static void convertFromChar(std::string str);
	static void convertFromInt(std::string str);
	static void convertFromFloat(std::string str);
	static void convertFromDouble(std::string str);

    public:
	~ScalarConverter();

	static void convert(const std::string str);
};

#endif
