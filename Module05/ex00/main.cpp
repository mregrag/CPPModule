/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:23:56 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/20 14:14:37 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main(void)
{
    try 
    {
	Bureaucrat John("John", 150);
	std::cout << John << std::endl;
    } 
    catch (std::exception& e) 
    {
	std::cout << "Error: " << e.what() << std::endl;
    }
    try
    {
	Bureaucrat bob("bob", 1);
	std::cout << bob << std::endl;
    }

    catch (std::exception& e) 
    {
	std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}
