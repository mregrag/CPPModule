/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:09 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/25 23:46:45 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Roboot("RobotOne");

    Roboot.attack("Enemy");
    Roboot.takeDamage(5);
    Roboot.beRepaired(3);
    
    return 0;
}
