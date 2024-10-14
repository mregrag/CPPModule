/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:09:55 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/14 02:34:09 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i] = Zombie(name);
	return (horde);
}
