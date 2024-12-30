/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/11 22:36:33 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "[" << this->getType() << "]		Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
    std::cout << "[" << this->getType() << "]		Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << "[" << this->getType() << "]		Copy Assignment Operator Called" << std::endl;
    if (this != &rhs)
	Animal::operator=(rhs);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "[" << this->getType() << "]		Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "[" << this->getType() << "]:says		Meow! Meow! Meow!" << std::endl;
}
