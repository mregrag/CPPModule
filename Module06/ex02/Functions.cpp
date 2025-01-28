/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:28:54 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/24 20:16:14 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate()
{
    srand(time(0));
    int choice = rand() % 3;
    switch (choice)
    {
	case 0:
	    return new A();
	case 1:
	    return new B();
	case 2:
	    return new C();
    }
    return (0);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
	std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
	std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
	std::cout << "C" << std::endl;
    else
	std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
	(void)dynamic_cast<A&>(p);
	std::cout << "A" << std::endl;
    }
    catch (std::exception&) {}

    try
    {
	(void)dynamic_cast<B&>(p);
	std::cout << "B" << std::endl;
    }
    catch (std::exception&) {}

    try
    {
	(void)dynamic_cast<C&>(p);
	std::cout << "C" << std::endl;
    }
    catch (std::exception&){}
}

