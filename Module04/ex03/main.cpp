/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:16:58 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 23:55:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	MateriaSource src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());

	Character me("Me");
	AMateria* tmp;

	tmp = src.createMateria("ice");
	me.equip(tmp);

	tmp = src.createMateria("cure");
	me.equip(tmp);

	Character bob("Bob");

	me.use(0, bob); // Uses ice
	me.use(1, bob); // Uses cure

	return 0;
}

