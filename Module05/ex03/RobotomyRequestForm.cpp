/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:29:04 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/14 22:53:37 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequest", 72, 45), target(target) 
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs), target(rhs.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if (this != &rhs) 
    {
	AForm::operator=(rhs);
	this->target = rhs.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    checkExecutability(executor);

    std::cout << "* drilling noises *" << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
	std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
	std::cout << "Robotomization of " << this->target << " has failed." << std::endl;
}
