/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:05:54 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/14 21:51:48 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**/
/*#include "Bureaucrat.hpp"*/
/*#include "ShrubberyCreationForm.hpp"*/
/*#include "RobotomyRequestForm.hpp"*/
/*#include "PresidentialPardonForm.hpp"*/
/*#include <iostream>*/
/**/
/*int main() {*/
/*    try {*/
/*        // Create bureaucrats*/
/*        Bureaucrat boss("Boss", 1);*/
/*        Bureaucrat secretary("Secretary", 70);*/
/*        Bureaucrat intern("Intern", 146);*/
/**/
/*        // Test ShrubberyCreationForm*/
/*        std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;*/
/*        ShrubberyCreationForm shrub("garden");*/
/**/
/*        intern.signForm(shrub);*/
/*        intern.executeForm(shrub);*/
/**/
/*	shrub.beSigned(intern);*/
/*	shrub.execute(intern);*/
/**/
/*        // Test RobotomyRequestForm*/
/*        std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;*/
/*        RobotomyRequestForm robot("target");*/
/*        secretary.signForm(robot);*/
/*        secretary.executeForm(robot);*/
/**/
/*        // Test PresidentialPardonForm*/
/*        std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;*/
/*        PresidentialPardonForm pardon("criminal");*/
/*        boss.signForm(pardon);*/
/*        boss.executeForm(pardon);*/
/**/
/*        // Test execution without signing*/
/*        std::cout << "\n=== Testing Unsigned Form ===" << std::endl;*/
/*        PresidentialPardonForm unsignedPardon("fugitive");*/
/*        boss.executeForm(unsignedPardon);*/
/**/
/*    } catch (std::exception& e) {*/
/*        std::cout << "Exception: " << e.what() << std::endl;*/
/*    }*/
/**/
/*    return 0;*/
/*}*/
/**/

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "\n=== Test 1: Creating Form and Bureaucrats ===" << std::endl;
        /*ShrubberyCreationForm form("home");*/
        /*RobotomyRequestForm form("home");*/
	RobotomyRequestForm form("home");
        Bureaucrat highGrade("Boss", 5);        // Can sign and execute
        /*Bureaucrat midGrade("Secretary", 140);  // Can sign but not execute*/
        /*Bureaucrat lowGrade("Intern", 150);     // Cannot sign or execute*/

        /*std::cout << form << std::endl;*/
        /*std::cout << highGrade << std::endl;*/
        /*std::cout << midGrade << std::endl;*/
        /*std::cout << lowGrade << std::endl;*/
        /**/
        /*std::cout << "\n=== Test 2: Low Grade Bureaucrat Attempts ===" << std::endl;*/
        /*// Try to sign with too low grade (should fail)*/
        /*lowGrade.signForm(form);*/
        /*// Try to execute unsigned form (should fail)*/
        /*lowGrade.executeForm(form);*/
        /**/
        /*std::cout << "\n=== Test 3: Mid Grade Bureaucrat Attempts ===" << std::endl;*/
        // Sign with adequate grade (should succeed)
        /*midGrade.signForm(form);*/
        // Try to execute with too low grade (should fail)
        /*midGrade.executeForm(form);*/

        std::cout << "\n=== Test 4: High Grade Bureaucrat Attempts ===" << std::endl;
        // Try to execute now signed form (should succeed)
	highGrade.signForm(form);
        highGrade.executeForm(form);

        /*std::cout << "\n=== Test 5: Creating Multiple Shrubberies ===" << std::endl;*/
        /*ShrubberyCreationForm form2("garden");*/
        /*highGrade.signForm(form2);*/
        /*highGrade.executeForm(form2);*/
        /**/
        /*std::cout << "\nCheck for created files: home_shrubbery and garden_shrubbery" << std::endl;*/
    }
    catch (std::exception &e)
    {
        std::cout << "Main exception: " << e.what() << std::endl;
    }

    return 0;
}

