/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:23:56 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/29 19:33:18 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
	Bureaucrat bob("Bob", 50);
	std::cout << bob << std::endl;

	bob.incrementGrade();
	std::cout << bob << std::endl;

	bob.decrementGrade();
	std::cout << bob << std::endl;

	Bureaucrat high("High", 150);
	high.decrementGrade();
	std::cout << high << std::endl;
    }

    catch (std::exception& e)
    {
	std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
	Bureaucrat low("Low", 150);
	std::cout << low << std::endl;
    }

    catch (std::exception& e)
    {
	std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}
