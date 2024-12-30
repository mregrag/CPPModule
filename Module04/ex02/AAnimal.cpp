/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:38:40 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/11 23:43:53 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "[AAnimal]	Default Constructor Created" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : type(type)
{
    std::cout << "[AAnimal]	parameterized constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& rhs)
{
    std::cout << "[AAnimal]	copy constructor called" << std::endl;
    *this = rhs;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
    std::cout << "[AAnimal]	copy assignment operator called" << std::endl;
    if (this != &rhs)
	this->type = rhs.getType();
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "[AAnimal]	Destructor Called" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

std::string const& AAnimal::getType() const
{
    return (this->type);
}
