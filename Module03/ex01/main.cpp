/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:09 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/27 17:23:33 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "-------------Creating ClapTrap-------------" << std::endl;
	ClapTrap clap("Clappy");

	std::cout << "-------------Creating ScavTrap-------------" << std::endl;
	ScavTrap scav("Scavvy");

	std::cout << "-------------actions-----------------------" << std::endl;
	clap.attack("Enemy");
	scav.attack("Enemy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "--------------Destructors-------------------" << std::endl;

	return (0);
}

