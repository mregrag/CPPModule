/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:05:54 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/19 19:37:02 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
	Bureaucrat president("President", 5);
	Bureaucrat manager("Manager", 40);
	Bureaucrat intern("Intern", 150);

	std::cout << "========== Testing ShrubberyCreationForm ==========" << std::endl;

	ShrubberyCreationForm shrub("garden");
	manager.signForm(shrub);
	manager.executeForm(shrub);

	std::cout << "========== Testing RobotomyRequestForm ==========" << std::endl;

	RobotomyRequestForm robotomy("Bender");
	manager.signForm(robotomy);
	manager.executeForm(robotomy);

	std::cout << "========== Testing PresidentialPardonForm ==========" << std::endl;

	PresidentialPardonForm pardon("Criminal");
	president.signForm(pardon);
	president.executeForm(pardon);

	std::cout << "========== Testing Execution Without Signing ==========" << std::endl;

	PresidentialPardonForm unsignedForm("Another Criminal");
	president.executeForm(unsignedForm);

	std::cout << "========== Testing Execution With Too Low Grade ==========" << std::endl;
	intern.executeForm(pardon);

    }
    catch (const std::exception& e)
    {
	std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
