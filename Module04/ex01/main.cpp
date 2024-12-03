/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/02 23:20:48 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>

void leaks(void)
{
	system("leaks polymorphism");
}

int main()
{
	atexit(leaks);
	const int numAnimals = 6;
	Animal* animals[numAnimals];

	for (int i = 0; i < numAnimals / 2; ++i)
		animals[i] = new Dog();

	for (int i = numAnimals / 2; i < numAnimals; ++i)
		animals[i] = new Cat();

	for (int i = 0; i < numAnimals; ++i)
		animals[i]->makeSound();

	Dog dog1;
	dog1.getBrain()->setIdea(0, "Chase the ball");
	Dog dog2 = dog1;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;

	dog2.getBrain()->setIdea(0, "Protect the house");

	std::cout << "-----------After Modefication ----------" << std::endl;
	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << "-----------Destructors--------" << std::endl;
	for (int i = 0; i < numAnimals; ++i)
		delete animals[i];

	return (0);
}

