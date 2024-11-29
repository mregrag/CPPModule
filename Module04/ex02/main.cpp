/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 23:12:42 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Attempting to instantiate an abstract class should fail:
	// Animal* animal = new Animal(); // This should cause a compilation error!

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	dog->makeSound();

	cat->makeSound();

	std::cout << "-----------Destructors--------" << std::endl;
	delete dog;
	delete cat;

	return (0);
}

