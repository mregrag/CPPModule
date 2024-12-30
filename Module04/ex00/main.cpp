/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/13 15:14:30 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----------Testing Animal -----------" << std::endl;
    Animal* animal = new Animal();

    std::cout << "------------------------------------" << std::endl;
    Animal* dog = new Dog();
    std::cout << "------------------------------------" << std::endl;
    Animal* cat = new Cat();
    std::cout << "------------------------------------" << std::endl;

    std::cout << dog->getType() << " " << std::endl;
    std::cout << animal->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    std::cout << "--------------Destructors----------" << std::endl;
    delete animal;
    delete dog;
    delete cat;

    std::cout << "-----Testing WrongAnimal----------" << std::endl;

    WrongAnimal* wrongMeta = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << wrongMeta->getType() << " " << std::endl;

    wrongMeta->makeSound();
    wrongCat->makeSound();

    std::cout << "------------Destructors----------" << std::endl;

    delete wrongMeta;
    delete wrongCat;

    return (0);
}

