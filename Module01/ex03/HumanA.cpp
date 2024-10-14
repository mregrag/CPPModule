/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:52:59 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/14 03:56:31 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon): name(name), weapon(weapon)
{
};

void HumanA::attack() const 
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
