/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:23:56 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/20 19:27:46 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bob("Bob", 1);
    std::cout << bob << std::endl;

    try 
    {
	Bureaucrat john("John", 151);
    } 
    catch (std::exception& e) 
    {
	std::cout << "Error: " << e.what() << std::endl;
    }
    try
    {
	Bureaucrat john("John", 0);
    }
    
    catch (std::exception& e) 
    {
	std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}

