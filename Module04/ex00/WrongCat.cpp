/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:55:09 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/29 18:16:27 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "[" << this->type << "]		Default Constructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs)
{
	std::cout << "[" << this->type << "]		Copy Constructor Called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "[" << this->type << "]		Copy Assignment Operator Called" << std::endl;
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[" << this->type << "]		Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "[" << this->type << "]:says		Meow! Meow! Meow!" << std::endl;
}
