/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:05:11 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/31 11:43:43 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie	*horde = ZombieHorde(5, "zombie");
	if (horde)
	{
		for(int i = 0; i < 5; i++)
			horde[i].announce();
		delete [] horde;
	}
	return (0);
}
