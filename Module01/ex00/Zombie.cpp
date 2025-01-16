/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:49:11 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/15 14:39:42 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <SDL2/SDL.h>


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
