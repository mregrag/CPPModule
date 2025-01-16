/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:34:04 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/15 22:27:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
	std::cout << "Usage: ./convert <literal>" << std::endl;;
	return (1);
    }

    ScalarConverter::convert(argv[1]);

    return (0);
}

