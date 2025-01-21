/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:05:54 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/18 21:39:44 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        // Create intern and bureaucrat
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);

        // Test 1: Create and use RobotomyRequestForm
        std::cout << "\n=== Test 1: RobotomyRequestForm ===" << std::endl;
        AForm* rrf = someRandomIntern.makeForm("robotomy equest", "Bender");
        if (rrf)
	{
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete (rrf);
        }

        /*// Test 2: Create and use ShrubberyCreationForm*/
        /*std::cout << "\n=== Test 2: ShrubberyCreationForm ===" << std::endl;*/
        /*AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");*/
        /*if (scf) {*/
        /*    boss.signForm(*scf);*/
        /*    boss.executeForm(*scf);*/
        /*    delete scf;*/
        /*}*/
        /**/
        /*// Test 3: Create and use PresidentialPardonForm*/
        /*std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;*/
        /*AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");*/
        /*if (ppf) {*/
        /*    boss.signForm(*ppf);*/
        /*    boss.executeForm(*ppf);*/
        /*    delete ppf;*/
        /*}*/
        /**/
        /*// Test 4: Try to create non-existent form*/
        /*std::cout << "\n=== Test 4: Invalid Form ===" << std::endl;*/
        /*AForm* invalid = someRandomIntern.makeForm("invalid form", "Target");*/
        /*if (invalid) {*/
        /*    delete invalid;*/
        /*}*/

    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

