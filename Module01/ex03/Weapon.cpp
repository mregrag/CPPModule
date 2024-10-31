/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:38:19 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/31 12:27:43 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(const std::string& type) : type(type)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType(void) const
{
	return (type);
}

void	Weapon::setType(const std::string& type)
{
	this->type = type;
}
