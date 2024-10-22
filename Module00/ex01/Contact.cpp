/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:06:15 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/21 05:09:47 by mregrag          ###   ########.fr       */
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

std::string Contact::getFirstName() const 
{
	return (this->firstName);
}

std::string Contact::getLastName() const 
{
	return (this->lastName);
}

std::string Contact::getNickname() const
{
	return (this->nickName);
}

void Contact::displayContact() const
{
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickName << std::endl;
	std::cout << "Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}
