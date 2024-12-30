/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:16:58 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/14 14:31:18 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    
    std::cout << "------------------------------------" << std::endl;

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    std::cout << "------------------------------------" << std::endl;

    ICharacter* me = new Character("me");
    std::cout << "------------------------------------" << std::endl;

    AMateria *tmp;
    std::cout << "------------------------------------" << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << "------------------------------------" << std::endl;

    ICharacter* bob = new Character("bob");

    std::cout << "------------------------------------" << std::endl;

    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << "------------------------------------" << std::endl;

    std::cout << "------------Destructors----------" << std::endl;

    delete bob;
    std::cout << "------------------------------------" << std::endl;
    delete me;
    std::cout << "------------------------------------" << std::endl;
    delete src;
    std::cout << "------------------------------------" << std::endl;

    return (0);
}
