/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:35:44 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/08 16:30:48 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <cstdlib>
#include "Derived.hpp"

Base* generate()
{
    srand(time(0));
    int random = rand() % 3;

    if (random == 0)
	return (new A());
    else if (random == 1)
	return (new B());
    else if (random == 2)
	return (new C());
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
	std::cout << "The type using a pointer is : A" << std::endl;
    else if (dynamic_cast<B*>(p))
	std::cout << "The type using a pointer is : B" << std::endl;
    else if (dynamic_cast<C*>(p))
	std::cout << "The type using a pointer is : C" << std::endl;
    else 
	std::cout << "Unkown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
	dynamic_cast<A&>(p);
	std::cout << "The type using a refrence is : A" << std::endl;
    }
    catch (const std::exception& e)
    {
	std::cout << "Error : " << e.what() << std::endl;
    }
    try
    {
	dynamic_cast<B&>(p);
	std::cout << "The type using a refrence is : B" << std::endl;
    }
    catch (const std::exception& e)
    {
	std::cout << "Error : " << e.what() << std::endl;
    }
    try
    {
	dynamic_cast<C&>(p);
	std::cout << "The type using a refrence is : C" << std::endl;
    }
    catch (const std::exception& e)
    {
	std::cout << "Error : " << e.what() << std::endl;
    }
}

int main(void)
{
    Base* baseptr = generate();

    identify(baseptr);
    identify(*baseptr);

    delete baseptr;

    return (0);
}
