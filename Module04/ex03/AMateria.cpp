/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:17:44 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/10 14:44:15 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("Unknown")
{
    std::cout << "[AMateria]	Default Constructor Called" << std::endl;
}

AMateria::AMateria(const std::string &type) : type(type)
{
    std::cout << "[AMateria]	Paramerized Constructor Called" << std::endl;
}

AMateria::AMateria(const AMateria &rhs) : type(rhs.type)
{
    std::cout << "[AMateria]	Copy Constructor Called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria &rhs)
{
    std::cout << "[AMateria]	Copy Assignment operator Called" << std::endl;
    (void)rhs;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "[AMateria]	Destructor Called" << std::endl;
}

const std::string &AMateria::getType() const 
{
    return (this->type); 
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses Materia on " << target.getName() << " *" << std::endl;
}
