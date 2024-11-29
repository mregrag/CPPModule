/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 20:58:49 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// Test for Animal, Dog, and Cat
	std::cout << "------Testing Animal and WrongCat-------" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "--------------------" << std::endl;
	const Animal* dog = new Dog();
	std::cout << "--------------------" << std::endl;
	const Animal* cat = new Cat();
	std::cout << "--------------------" << std::endl;

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	std::cout << "-----------Destructors--------" << std::endl;
	delete meta;
	delete dog;
	delete cat;

	std::cout << "-----Testing WrongAnimal and WrongCat:-----" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;

	wrongMeta->makeSound();
	wrongCat->makeSound();

	std::cout << "-----------Destructors--------" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	return (0);
}

