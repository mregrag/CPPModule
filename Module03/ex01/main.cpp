/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:09 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/24 18:09:55 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	/*std::cout << "Creating ClapTrap:" << std::endl;*/
	/*ClapTrap clap("Clappy");*/
	/**/
	/*std::cout << "\nCreating ScavTrap:" << std::endl;*/
	/*ScavTrap scav("Scavvy");*/
	/**/
	/*std::cout << "\nTesting actions:" << std::endl;*/
	/*clap.attack("Enemy");*/
	/*scav.attack("Enemy");*/
	/*scav.takeDamage(30);*/
	/*scav.beRepaired(20);*/
	/*scav.guardGate();*/
	/**/
	/*std::cout << "\nDestruction phase:" << std::endl;*/

	ScavTrap scav2("Enemy");
	scav2.guardGate();

	return (0);
}

