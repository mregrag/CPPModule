/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:09 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/08 19:18:48 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <stdio.h>

int main(void)
{
    ClapTrap Roboot("RobotOne");
    printf("hello world\n");

    Roboot.attack("Enemy");
    Roboot.takeDamage(5);
    Roboot.beRepaired(3);

    std::cout << "\n------------------Destructors---------------------" << std::endl;
    
    return 0;
}
