/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 20:55:00 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "[Cat]		Default Constructor Called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const std::string& type) : Animal(type)
{
	std::cout << "[Cat]		parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	std::cout << "[Cat]		copy Constructor Called " << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "[Cat]		copy assignment operator called" << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat]		Destructor Called" << std::endl;
}

std::string Cat::getType() const
{
	return (this->type);
}

void Cat::makeSound() const
{
	std::cout << "[Cat]		Meow! Meow! Meow! Meow!" << std::endl;
}
