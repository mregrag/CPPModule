/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:09 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/27 19:44:57 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "-------------Creating DiamondTrap-------------" << std::endl;

	DiamondTrap diamond("root");

	std::cout << "-------------actions--------------------------" << std::endl;
	diamond.attack("Enemy");
	diamond.takeDamage(30);
	diamond.beRepaired(20);
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();



	std::cout << "--------------Destructors-------------------" << std::endl;

	return (0);
}
