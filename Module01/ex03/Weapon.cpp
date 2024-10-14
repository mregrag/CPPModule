/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:52:29 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/14 04:26:34 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std:: string& type): type(type)
{
};

const std::string& Weapon::getType() const
{
	return (this->type);
}

void	Weapon::setType(const std::string& type)
{
	this->type = type;
}
