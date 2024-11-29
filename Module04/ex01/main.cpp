/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 23:07:49 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Array of Animal objects
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	// Test deep copy
	Dog* originalDog = new Dog();
	originalDog->getBrain()->setIdea(0, "Chase the ball!");

	Dog* copiedDog = new Dog(*originalDog);
	std::cout << "Original Dog's idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog's idea: " << copiedDog->getBrain()->getIdea(0) << std::endl;

	// Modify the copy's brain to verify deep copy
	copiedDog->getBrain()->setIdea(0, "Eat food!");
	std::cout << "After modification:" << std::endl;
	std::cout << "Original Dog's idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog's idea: " << copiedDog->getBrain()->getIdea(0) << std::endl;

	// Cleanup
	delete originalDog;
	delete copiedDog;

	for (int i = 0; i < 4; ++i) {
		delete animals[i];
	}

	return 0;
}

