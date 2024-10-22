/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +j#+           */
/*   Created: 2024/10/05 22:05:29 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/21 06:37:26 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), index(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::Truncate(const std::string& str) const
{
	std::string result = str;
	std::replace(result.begin(), result.end(), '\t', ' ');
	if (result.length() > 10)
		return (result.substr(0, 9) + ".");
	return (result);
}

std::string PhoneBook::getInfo(const std::string& prompt, int info) const
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

bool PhoneBook::isDigitsOnly(const std::string& str) const
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
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


void PhoneBook::searchContact() const
{
	if (count == 0)
	{
		std::cout << "\033[33mPhonebook is empty.\033[0m" << std::endl;
		return;
	}
	displayAllContacts();
	std::string input;
	int index = 0;
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
		if (index >= this->count || index < 0)
		{
			std::cout << "Contact not found" << std::endl;
			continue;
		}
		break;
	}
	contacts[index].displayContact();
}

void PhoneBook::displayAllContacts() const
{
	std::cout << std::string(44, '-') << std::endl;
	std::cout << std::setw(10)  << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << std::string(44, '-') << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		std::cout << std::setw(10) << std::right << Truncate(contacts[i].getFirstName())<< "|";
		std::cout << std::setw(10) << std::right << Truncate(contacts[i].getLastName())<< "|";
		std::cout << std::setw(10) << std::right << Truncate(contacts[i].getNickname())<< "|";
		std::cout << std::endl;
	}
}
