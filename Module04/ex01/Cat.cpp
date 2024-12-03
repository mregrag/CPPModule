/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/02 20:30:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "[" << this->type << "]		Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs), brain(new Brain(*rhs.brain))
{
	std::cout << "[" << this->type << "]		Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "[" << this->type << "]		Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
	if (brain)
		delete brain;
	brain = new Brain(*rhs.brain);
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "[" << this->type << "]		Destructor Called" << std::endl;
}

std::string Cat::getType() const
{
	return (this->type);
}

void Cat::makeSound() const
{
	std::cout << "[" << this->type << "]:says		Meow! Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (this->brain);
}
