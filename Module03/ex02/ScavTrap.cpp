/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:24:40 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/25 17:14:16 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "[ScavTrap] default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "[ScavTrap] parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "[ScavTrap] copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "[ScavTrap] assignment operator called" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] destructor called for " << name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << "[ScavTrap] " << name << " can't attack!" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "[ScavTrap] " << name << " attacks " << target 
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] " << name << " is now in Gate keeper mode" << std::endl;
}

