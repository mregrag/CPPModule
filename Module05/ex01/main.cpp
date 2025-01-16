/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:23:56 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/14 15:32:49 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "\n=== Test 1: Form Creation ===" << std::endl;
        try 
	{
            Form validForm("Valid Form", 100, 50);
            std::cout << validForm << std::endl;
            
            Form invalidForm("Invalid Form", 1, 50);  
        }
	catch (const std::exception& e)
	{
            std::cout << "Error creating form: " << e.what() << std::endl;
        }

        std::cout << "\n=== Test 2: Valid Signing ===" << std::endl;
        Bureaucrat boss("Boss", 1);
        Form easyForm("Easy Form", 100, 50);
        std::cout << easyForm << std::endl;
        boss.signForm(easyForm);
        std::cout << easyForm << std::endl;

        /*std::cout << "\n=== Test 3: Invalid Signing ===" << std::endl;*/
        /*Bureaucrat intern("Intern", 150);*/
        /*Form hardForm("Hard Form", 1, 1);*/
        /*std::cout << hardForm << std::endl;*/
        /*intern.signForm(hardForm);*/
        /*std::cout << hardForm << std::endl;*/

    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    return (0);
}
