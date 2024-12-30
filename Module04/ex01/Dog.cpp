/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:03 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/13 16:38:47 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
    std::cout << "[" << this->getType() << "]		Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs), brain(new Brain(*rhs.brain))
{
    std::cout << "[" << this->getType() << "]		Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << "[" << this->getType() << "]		Copy Assignment Operator Called" << std::endl;
    if (this != &rhs)
    {
	Animal::operator=(rhs);
	if (this->brain)
	    delete this->brain;
	if (rhs.brain)
	    this->brain = new Brain(*rhs.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    this->brain = NULL;
    std::cout << "[" << this->getType() << "]		Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "[" << this->getType() << "]:says		Woof! Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return (this->brain);
}
