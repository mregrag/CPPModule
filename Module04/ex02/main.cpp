/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/13 18:06:36 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();

    dog->makeSound();

    cat->makeSound();

    std::cout << "-----------Destructors--------" << std::endl;

    delete dog;
    delete cat;

    return (0);
}
