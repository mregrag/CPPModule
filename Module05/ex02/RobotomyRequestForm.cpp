/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:29:04 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/14 21:52:59 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy", 72, 45), target(target) 
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

    std::srand(time(0));
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2)
	std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
	std::cout << "Robotomization of " << this->target << " has failed." << std::endl;
}
