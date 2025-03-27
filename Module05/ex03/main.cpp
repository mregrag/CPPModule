/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:05:54 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/20 15:51:42 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern Intern;
        Bureaucrat boss("Boss", 5);

        std::cout << "========Test 1: RobotomyRequestForm==========" << std::endl;
        AForm* rrf = Intern.makeForm("robotomy request", "Bender");
        if (rrf)
	{
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete (rrf);
        }

        std::cout << "========Test 2: ShrubberyCreationForm==========" << std::endl;
        AForm* scf = Intern.makeForm("shrubbery creation", "Garden");
        if (scf)
	{
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }

        std::cout << "========Test 3: PresidentialPardonForm==========" << std::endl;
        AForm* ppf = Intern.makeForm("presidential pardon", "Criminal");
        if (ppf)
	{
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
            delete ppf;
        }

        std::cout << "========Test 4: Invalid Form==========" << std::endl;
        AForm* invalid = Intern.makeForm("invalid form", "Target");
        if (invalid) 
	{
            delete invalid;
        }

    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
