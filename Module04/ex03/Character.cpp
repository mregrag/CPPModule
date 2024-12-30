/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:41:56 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/13 18:10:00 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Unknown"), floor_count(0)
{
    std::cout << "[Character]	Default Constructor Called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
	this->inventory[i] = NULL;
	this->floor[i] = NULL;
    }
}

Character::Character(const std::string& name) : name(name), floor_count(0)
{
    std::cout << "[Character]	Paramerized Constructor Called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
	this->inventory[i] = NULL;
	this->floor[i] = NULL;
    }
}

Character::Character(const Character& rhs) : name(rhs.name), floor_count(rhs.floor_count)
{
    std::cout << "[Character]	Copy Constructor Called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
	if (rhs.inventory[i])
	    this->inventory[i] = rhs.inventory[i]->clone();
	else 
	    this->inventory[i] = NULL;
    }

    for (int i = 0; i < floor_count; ++i)
    {
	if (rhs.floor[i])
	    this->floor[i] = rhs.floor[i]->clone();
	else 
	    this->floor[i] = NULL;
    }
}

Character& Character::operator=(const Character& rhs)
{
    std::cout << "[Character]	Copy Assignment operator Called" << std::endl;
    if (this != &rhs)
    {
	this->name = rhs.name;
	for (int i = 0; i < 4; ++i)
	{
	    delete this->inventory[i];
	    this->inventory[i] = NULL;
	    if (rhs.inventory[i])
		this->inventory[i] = rhs.inventory[i]->clone();
	}

	for (int i = 0; i < floor_count; ++i)
	{
	    delete this->floor[i];
	    this->floor[i] = NULL;
	    if (rhs.floor[i])
		this->floor[i] = rhs.floor[i]->clone();
	}
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "[Character]	Destructor Called" << std::endl;
    for (int i = 0; i < 4; ++i)
	delete this->inventory[i];

    for (int i = 0; i < floor_count; i++)
	delete this->floor[i];
}

ICharacter::~ICharacter()
{
    std::cout << "[ICharacter]	Destructor Called" << std::endl;
}

const std::string& Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (!m)
	return ;
    for (int i = 0; i < 4; ++i)
    {
	    if (this->inventory[i] == m)
		return;
    }

    for (int i = 0; i < 4; ++i)
    {
	if (!this->inventory[i])
	{
	    this->inventory[i] = m;
	    return;
	}
    }
    delete m;
    m = NULL;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !this->inventory[idx] || this->floor_count > 4)
	return;
    this->floor[floor_count++] = this->inventory[idx];
    this->inventory[idx] = NULL; 
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !this->inventory[idx])
	return;
    this->inventory[idx]->use(target);
}
