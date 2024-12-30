/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:49:11 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/08 20:19:34 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{	
	std::cout << this->name << " is destroyed " << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
