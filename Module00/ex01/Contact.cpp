/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:06:15 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/24 01:21:55 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(const std::string& fname)
{
    this->firstName = fname;
}

void Contact::setLastName(const std::string& lname)
{
    this->lastName = lname;
}

void Contact::setNickname(const std::string& nname)
{
    this->nickName = nname;
}

void Contact::setPhoneNumber(const std::string& phone)
{
    this->phoneNumber = phone;
}

void Contact::setDarkestSecret(const std::string& secret)
{
    this->darkestSecret = secret;
}

std::string Contact::getFirstName(void) const 
{
	return (this->firstName);
}

std::string Contact::getLastName(void) const 
{
	return (this->lastName);
}

std::string Contact::getNickname(void) const
{
	return (this->nickName);
}

void Contact::displayContact(void) const
{
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickName << std::endl;
	std::cout << "Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}
