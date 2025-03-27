/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:23:56 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/20 14:33:39 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try 
    {
	std::cout << "========== Form Creation ==========" << std::endl;
	Bureaucrat boss("Boss", 150);
	Form Form1("Form1", 100, 1);
	std::cout << Form1 << std::endl;
	std::cout << boss << std::endl;

	std::cout << "========== Test 2: Valid Signing ==========" << std::endl;

	boss.signForm(Form1);
	std::cout << Form1 << std::endl;

    }
    catch (const std::exception& e)
    {
	std::cout << "Error: " << std::endl;
    }

    return (0);
}
