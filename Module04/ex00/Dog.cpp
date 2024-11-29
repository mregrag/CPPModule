/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:03 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 20:54:36 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "[Dog]		Default Constructor Called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const std::string& type) : Animal(type)
{
	std::cout << "[Dog]		parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	std::cout << "[Dog]		copy Constructor Called " << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "[Dog]		copy assignment operator called" << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog]		Destructor Called" << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}

void Dog::makeSound() const
{
	std::cout << "[Dog]		Woof! Woof! Woof! Woof!" << std::endl;
}
