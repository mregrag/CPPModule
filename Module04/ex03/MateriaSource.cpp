/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:47:47 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/13 17:58:49 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "[MateriaSource]	Default Constructor Called" << std::endl;
    for (int i = 0; i < 4; ++i)
	this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
    std::cout << "[MateriaSource]	Copy Constructor Called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
	if (rhs.materias[i])
	    this->materias[i] = rhs.materias[i]->clone();
	else 
	    this->materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    std::cout << "[MateriaSource]	Copy Assignment operator Called" << std::endl;
    if (this != &rhs)
    {
	for (int i = 0; i < 4; ++i)
	{
	    delete this->materias[i];
	    this->materias[i] = NULL;
	    if (rhs.materias[i])
		this->materias[i] = rhs.materias[i]->clone();
	}
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "[MateriaSource]	Destructor Called" << std::endl;
    for (int i = 0; i < 4; ++i)
	delete this->materias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
	return;
    for (int i = 0; i < 4; ++i)
    {
	if (!this->materias[i])
	{
	    this->materias[i] = m;
	    return;
	}
    }
    delete m;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < 4; ++i)
    {
	if (this->materias[i] && this->materias[i]->getType() == type)
	    return (this->materias[i]->clone());
    }
    std::cout << "MateriaSource Unknown" << std::endl;
    return (NULL);
}
