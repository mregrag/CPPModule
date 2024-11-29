/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:59 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 23:09:26 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "[Animal]	Default Constructor Created" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "[Animal]	parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal& rhs)
{
	std::cout << "[Animal]	copy constructor called" << std::endl;
	*this = rhs;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "[Animal]	copy assignment operator called" << std::endl;
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
