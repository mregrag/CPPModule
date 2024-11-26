/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:09 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/20 18:05:42 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "iostream"

int main()
{
    std::cout << "Creating FragTrap:" << std::endl;
    FragTrap frag("Fraggy");
    
    std::cout << "\nTesting actions:" << std::endl;
    frag.attack("Enemy");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();
    
    std::cout << "\nDestruction phase:" << std::endl;
    return 0;
}
