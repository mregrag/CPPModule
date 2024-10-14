/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +j#+           */
/*   Created: 2024/10/05 22:05:29 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/12 23:56:50 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : count(0), index(0)
{
}

PhoneBook::~PhoneBook()
{
}

bool PhoneBook::isDigitsOnly(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

std::string PhoneBook::Truncate(const std::string& str, size_t maxLength)
{
	std::string result = str;
	std::replace(result.begin(), result.end(), '\t', ' ');
	if (result.length() > maxLength)
		result = result.substr(0, maxLength - 1) + ".";
	return (result);
}

void PhoneBook::addContact()
{
	std::string firstName = getInfo("First Name", 1);
	if (firstName.empty())
		return;

	std::string lastName = getInfo("Last Name", 2);
	if (lastName.empty())
		return;

	std::string nickName = getInfo("Nick Name", 3);
	if (nickName.empty())
		return;

	std::string phoneNumber = getInfo("Phone Number", 4);
	if (phoneNumber.empty())
		return;

	std::string darkestSecret = getInfo("Darkest Secret", 3);
	if (darkestSecret.empty())
		return;
	this->contacts[this->index % 8].setFirstName(firstName);
	this->contacts[this->index % 8].setLastName(lastName);
	this->contacts[this->index % 8].setNickname(nickName);
	this->contacts[this->index % 8].setPhoneNumber(phoneNumber);
	this->contacts[this->index % 8].setDarkestSecret(darkestSecret);

	this->index++;
	if (count < 8)
		this->count++;
	std::cout << "\033[32mContact added successfully.\033[0m" << std::endl;
}

std::string PhoneBook::getInfo(const std::string& prompt, int info)
{
	std::string input;
	while (true)
	{
		std::cout << prompt << ": ";
		if (!std::getline(std::cin, input))
			return ("");
		if (info == 4 && (input.empty() || !isDigitsOnly(input)))
		{
			std::cout << "\033[31mError: Phone number must be only digits.\033[0m" << std::endl;
			continue;
		}
		if (input.empty())
			continue;
		return (input);
	}
}

void PhoneBook::searchContact()
{
	if (count == 0)
	{
		std::cout << "\033[33mPhonebook is empty.\033[0m" << std::endl;
		return;
	}
	displayAllContacts();
	std::string input;
	int index = -1;
	while (true)
	{
		std::cout << "Enter the index of the contact: ";
		if (!std::getline(std::cin, input))
			return ;
		if (input.length() > 1 || !isDigitsOnly(input))
		{
			std::cout << "Invalid index" << std::endl;
			continue;
		}
		if (input.empty())
			continue;
		index = (input[0] - 48) - 1;
		if (index >= count || index < 0)
		{
			std::cout << "Contact not found" << std::endl;
			continue;
		}
		break;
	}
	contacts[index].displayContact();
}

void PhoneBook::displayAllContacts()
{
	std::cout << std::setw(10) << std::right << "Index" << "|"
		<< std::setw(10) << std::right << "First Name" << "|"
		<< std::setw(10) << std::right << "Last Name" << "|"
		<< std::setw(10) << std::right << "Nickname" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		std::cout << std::setw(10) << std::right << Truncate(contacts[i].getFirstName(), 10)<< "|";
		std::cout << std::setw(10) << std::right << Truncate(contacts[i].getLastName(), 10)<< "|";
		std::cout << std::setw(10) << std::right << Truncate(contacts[i].getNickname(), 10)<< "|";
		std::cout << std::endl;
	}
}
