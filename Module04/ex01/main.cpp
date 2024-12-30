/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/13 16:36:06 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "----- Test 1: Array of Animals -----" << std::endl;

    Animal* animals[4];

    for (int i = 0; i < 2; ++i)
    {
	animals[i] = new Dog();
	animals[i + 2] = new Cat();
    }

    for (int i = 0; i < 4; ++i)
	animals[i]->makeSound();

    std::cout << "----- Test 2: Deep Copy -----" << std::endl;
    Dog originalDog;
    Dog copiedDog;

    originalDog.getBrain()->setIdea(0, "I want to play ball");
    copiedDog = originalDog;

    std::cout << "originalDog idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "copiedDog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;

    copiedDog.getBrain()->setIdea(0, "I want to sleep");

    std::cout << "-----------After Modefication ----------" << std::endl;
    std::cout << "Dog1 idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;

    std::cout << "-----------Destructors--------" << std::endl;
    for (int i = 0; i < 4; ++i)
	delete animals[i];

    return (0);
}
