/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:37:38 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/03 01:31:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "[Cure]	Default Constructor Called" << std::endl;
}

Cure::Cure(const Cure& rhs) : AMateria(rhs)
{
	std::cout << "[Cure]	Copy Constructor Called" << std::endl;
}

Cure& Cure::operator=(const Cure& rhs)
{
	std::cout << "[Cure]	Copy Assingment Operator Called" << std::endl;
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

Cure::~Cure()
{
	std::cout << "[Cure]	Destructor Called" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

