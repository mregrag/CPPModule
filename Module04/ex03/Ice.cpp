/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:34:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/11 00:10:00 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "[Ice]		Default Constructor Called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other.type)
{
	std::cout << "[Ice]		Copy Constructor Called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    std::cout << "[Cure]		Copy Assingment Operator Called" << std::endl;
    if (this != &other)
	type = other.type;
    return *this;
}

Ice::~Ice()
{
    std::cout << "[Ice]		Destructor Called" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
