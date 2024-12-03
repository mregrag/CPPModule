/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:03 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/02 23:17:16 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "[" << this->type << "]		Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs), brain(new Brain(*rhs.brain))
{
	std::cout << "[" << this->type << "]		Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "[" << this->type << "]		Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[" << this->type << "]		Destructor Called" << std::endl;
	delete this->brain;
}

std::string Dog::getType() const
{
	return (this->type);
}

void Dog::makeSound() const
{
	std::cout << "[" << this->type << "]:says		Woof! Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (this->brain);
}
