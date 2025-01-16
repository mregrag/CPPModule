/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:26:45 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/15 14:42:13 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg(argv[i]);
			for (size_t j = 0; j < arg.length(); j++)
				std::cout << (char)std::toupper(arg[j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
