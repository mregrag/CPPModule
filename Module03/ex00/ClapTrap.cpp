/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:24 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/08 20:22:23 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[ClapTrap] default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[ClapTrap] parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	std::cout << "[ClapTrap] copy constructor called" << std::endl;
	*this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "[ClapTrap] assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->hitPoints = rhs.hitPoints;
		this->energyPoints = rhs.energyPoints;
		this->attackDamage = rhs.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " can't attack!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << name << " is already destroyed!" << std::endl;
		return;
	}
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << name << " can't repair itself!" << std::endl;
		return;
	}
	energyPoints--;
	hitPoints += amount;

	std::cout << name << " repairs itself for " << amount << " hit points. Current hit points: " << hitPoints << std::endl;
}
