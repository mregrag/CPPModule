/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:09 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/26 00:46:51 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    DiamondTrap diamond("root");
    std::cout << "-----------------" << std::endl;

    DiamondTrap test = diamond;

    test.whoAmI();
    
    /*diamond.whoAmI();*/
    /*diamond.attack("Enemy");*/
    /*diamond.takeDamage(30);*/
    /*diamond.beRepaired(20);*/
    /*diamond.highFivesGuys();*/
    /*diamond.guardGate();*/
    
    return 0;
}
