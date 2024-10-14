/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:22:28 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/14 01:43:53 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie *heap_zombie1 = newZombie("Heap Zombie1");
	Zombie *heap_zombie2 = newZombie("Heap Zombie2");
	Zombie *heap_zombie3 = newZombie("Heap Zombie3");
	Zombie *heap_zombie4 = newZombie("Heap Zombie4");
	Zombie Zombie1("1");
	Zombie Zombie2("2");
	Zombie Zombie3("3");
	Zombie Zombie4("4");

	heap_zombie1->announce();
	heap_zombie2->announce();
	heap_zombie3->announce();
	heap_zombie4->announce();

	randomChump("Stack Zombie1");
	randomChump("Stack Zombie2");
	randomChump("Stack Zombie3");
	randomChump("Stack Zombie4");

	delete heap_zombie1;
	delete heap_zombie2;
	delete heap_zombie3;
	delete heap_zombie4;
	return (0);
}
