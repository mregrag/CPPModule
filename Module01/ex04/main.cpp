/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:57:11 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/30 12:31:41 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return (1);
	}

	FileReplace file(argv[1]);
	if (!file.replacestr(argv[2], argv[3]))
		return (1);
	return (0);
}

