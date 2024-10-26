/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:22:28 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/25 04:15:10 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie *heap_zombie1 = newZombie("Heap Zombie1");
	Zombie Zombie1("1");

	heap_zombie1->announce();

	randomChump("Stack Zombie1");
	delete heap_zombie1;
	return (0);
}
