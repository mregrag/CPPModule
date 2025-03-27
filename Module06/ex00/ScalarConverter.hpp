/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:36:11 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/08 16:33:53 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>

class ScalarConverter
{
    private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);

	static bool isChar(const std::string& str);
	static bool isInt(const std::string& str);
	static bool isFloat(const std::string& str);
	static bool isDouble(const std::string& str);
	static bool isPseudoLiteral(const std::string& str);

	static void convertFromChar(const std::string& str);
	static void convertFromInt(const std::string& str);
	static void convertFromFloat(const std::string& str);
	static void convertFromDouble(const std::string& str);

    public:
	~ScalarConverter();

	static void convert(const std::string str);
};

#endif
