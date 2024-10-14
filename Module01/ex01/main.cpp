/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:09:12 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/14 02:18:48 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie* zombie = zombieHorde(6, "zombie");
	for (int i = 0; i < 6; i++)
		zombie[i].announce();
	delete[] zombie;
	return (0);
}
