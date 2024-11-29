/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:59 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/29 18:01:11 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "[Animal]	Default Constructor Created" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "[Animal]	Parameterized Constructor Called" << std::endl;
}

Animal::Animal(const Animal& rhs)
{
	std::cout << "[Animal]	Copy Constructor Called" << std::endl;
	*this = rhs;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "[Animal]	Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[Animal]	Destructor Called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "[Animal]		make a generic sound. " << std::endl;
}
