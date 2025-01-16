/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:48:59 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/15 14:41:24 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <SDL2/SDL.h>

int	main(void)
{
	Zombie*	heap_zombie = newZombie("heap_zombie");

	heap_zombie->announce();

	randomChump("stack_zombie");

	{
		Zombie ob = Zombie("mohamed");
		ob.announce();
	}
	delete heap_zombie;
	return (0);
}
