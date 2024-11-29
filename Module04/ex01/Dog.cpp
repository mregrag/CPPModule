/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:03 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 22:51:55 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	std::cout << "[Dog]		Default Constructor Called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const std::string& type) : Animal(type)
{
	std::cout << "[Dog]		parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs), brain(new Brain(*rhs.brain))
{
	std::cout << "[Dog]		copy Constructor Called " << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "[Dog]		copy assignment operator called" << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
	if (brain)
		delete brain;
	brain = new Brain(*rhs.brain);
	return (*this);
}

Dog::~Dog()
{
	delete brain;
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

Brain* Dog::getBrain() const
{
	return (brain);
}
