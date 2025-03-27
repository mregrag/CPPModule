/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:09 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/27 17:45:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	std::cout << "-------------Creating ClapTrap-------------" << std::endl;
	ClapTrap clap("Clappy");

	std::cout << "-------------Creating FragTrap-------------" << std::endl;
	FragTrap frag("Fraggy");
    
	std::cout << "-------------actions-----------------------" << std::endl;
	frag.attack("Enemy");
	frag.takeDamage(30);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << "--------------Destructors-------------------" << std::endl;
    
    return 0;
}
