/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:23:56 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/16 21:35:32 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

double devide(int a, int b)
{
    if (b == 0)
	throw std::runtime_error("Division by zero is not allowed !");
    std::cout << "Hello world " << std::endl;
    return (static_cast<double>(a) / b);
}

int main()
{
    Bureaucrat bob("Bob", 1);
    std::cout << bob << std::endl;

    try 
    {
	Bureaucrat john("John", 0);
    } 
    catch (const std::exception& e) 
    {
	std::cout << "Error: " << e.what() << std::endl;
    }
    try 
    {
	Bureaucrat alice("Alice", 151);
    } 
    catch (const std::exception& e) 
    {
	std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}

