/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:55:32 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/13 15:13:00 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "[WrongAnimal]	Default Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
    std::cout << "[WrongAnimal]	Parameterized Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
{
    std::cout << "[WrongAnimal]	copy Constructor operator Called" << std::endl;
    *this = rhs;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    std::cout << "[WrongAnimal]	copy assignment operator Called" << std::endl;
    if (this != &rhs)
	this->type = rhs.getType();
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal]	Destructor Called" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal]	undefined sound " << std::endl;
}
