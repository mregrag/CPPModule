/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:34:04 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/29 23:38:45 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
	std::cout << "Usage: ./convert <literal>" << std::endl;;
	return (1);
    }

    float x = 5.545454f;
    std::cout << x << std::endl;
    ScalarConverter::convert(argv[1]);

    return (0);
}

