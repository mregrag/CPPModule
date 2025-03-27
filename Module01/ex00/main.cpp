/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:48:59 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/31 11:06:36 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	heap_zombie = newZombie("heap_zombie");

	heap_zombie->announce();

	randomChump("stack_zombie");

	delete heap_zombie;
	return (0);
}
