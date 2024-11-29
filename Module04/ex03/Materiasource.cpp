/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materiasource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:47:47 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 23:53:23 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	*this = rhs;
}

// Assignment Operator
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete templates[i];
			templates[i] = rhs.templates[i] ? rhs.templates[i]->clone() : NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		delete templates[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!templates[i])
		{
			templates[i] = m;
			return;
		}
	}

	std::cout << "MateriaSource is full! Cannot learn more Materia." << std::endl;
	delete m;
}

// Create Materia
AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (templates[i] && templates[i]->getType() == type)
			return (templates[i]->clone());
	}
	std::cout << "MateriaSource doesn't know this type: " << type << std::endl;
	return (NULL);
}
