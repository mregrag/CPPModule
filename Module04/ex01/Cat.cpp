/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/13 16:01:04 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"), brain(NULL)
{
    std::cout << "[" << this->getType() << "]		Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs), brain(new Brain(*rhs.brain))
{
    std::cout << "[" << this->getType() << "]		Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
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

Cat::~Cat()
{
    delete this->brain;
    std::cout << "[" << this->getType() << "]		Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "[" << this->type << "]:says		Meow! Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return (this->brain);
}
