/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:09:12 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/26 01:02:05 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie* zombie = zombieHorde(1, "zombie");
	if (zombie)
	{
		for (int i = 0; i < 1; i++)
			zombie[i].announce();
		delete[] zombie;
	}
	return (0);
}
