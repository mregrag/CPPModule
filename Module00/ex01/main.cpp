/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:07:16 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/23 22:12:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEOF" << std::endl;
			break;
		}
		if (command.empty())
			continue;
		if (command == "ADD" || command == "add")
			phoneBook.addContact();
		else if (command == "SEARCH" || command == "search")
			phoneBook.searchContact();
		else if (command == "EXIT" || command == "exit")
			break;
		else
			std::cout << "\033[31mError: Invalid command. Pleas try again.\033[0m" << std::endl;
		if (std::cin.eof())
		{
			std::cout << "\nEOF" << std::endl;
			break;
		}
	}
	return (0);
}
