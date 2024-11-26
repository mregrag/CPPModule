/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 06:29:16 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/25 17:20:46 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "[FragTrap] default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "[FragTrap] parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "[FragTrap] copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "[FragTrap] assignment operator called" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] destructor called for " << name << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << "[FragTrap] " << name << " can't attack!" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "[FragTrap] " << name << " viciously attacks " << target 
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "[FragTrap] " << name << " requests a high five! ✋" << std::endl;
}
