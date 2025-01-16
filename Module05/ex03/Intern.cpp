/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:17:53 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/15 17:00:51 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& rhs)
{
    (void)rhs;
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeShrubberyForm(const std::string& target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyForm(const std::string& target) const
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(const std::string& target) const
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    AForm* (Intern::*creator[3])(const std::string&) const = {
	&Intern::makeShrubberyForm,
	&Intern::makeRobotomyForm,
	&Intern::makePresidentialPardonForm};

    for (int i = 0; i < 3 ; i++)
    {
        if (formName == name[i])
	{
            AForm* form = (this->*creator[i])(target);
            std::cout << "Intern creates " << formName << std::endl;
            return (form);
        }
    }
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Form type not found!");
}
