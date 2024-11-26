/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 06:35:30 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/26 00:56:56 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DiamondTrap.cpp
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), name("Default")
{
	ClapTrap::name = this->name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "[DiamondTrap] default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "[DiamondTrap] parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) : ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs)
{
	std::cout << "[DiamondTrap] copy constructor called" << std::endl;
	this->name = rhs.name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
    if (this != &rhs)
    {
        name = rhs.name;
        ClapTrap::name = rhs.ClapTrap::name;
        hitPoints = rhs.hitPoints;
        energyPoints = rhs.energyPoints;
        attackDamage = rhs.attackDamage;
    }
    return (*this);
}


DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] destructor called for " << name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << name << " (ClapTrap name: " << ClapTrap::name << ")" << std::endl;
}
