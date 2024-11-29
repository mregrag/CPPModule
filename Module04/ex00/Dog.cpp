/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:03 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/29 18:00:23 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "[" << this->type << "]		Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	std::cout << "[" << this->type << "]		Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "[" << this->type << "]		Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[" << this->type << "]		Destructor Called" << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}

void Dog::makeSound() const
{
	std::cout << "[" << this->type << "]:says		Woof! Woof! Woof!" << std::endl;
}
