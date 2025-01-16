/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:36:11 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/15 23:44:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter
{
    private:
	/*ScalarConverter();*/
	/*ScalarConverter(const ScalarConverter& other);*/
	/*ScalarConverter& operator=(const ScalarConverter& other);*/

	// Helper methods for type detection
	static bool isChar(const std::string& str);
	static bool isInt(const std::string& str);
	static bool isFloat(const std::string& str);
	static bool isDouble(const std::string& str);

	// Helper methods for conversion
	static void convertFromChar(char value);
	static void convertFromInt(int value);
	static void convertFromFloat(float value);
	static void convertFromDouble(double value);

    public:
	~ScalarConverter();

	// Static conversion method
	static void convert(const std::string str);
};

#endif
