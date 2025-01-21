/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:05:17 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/18 20:46:42 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (this->gradeToSign < 1 || this->gradeToExecute < 1)
	throw GradeTooHighException();
    if (this->gradeToSign > 150 || this->gradeToExecute > 150)
	throw GradeTooLowException();
}

AForm::AForm(const AForm& rhs) : name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& rhs)
{
    if (this != &rhs)
	this->isSigned = rhs.isSigned;
    return (*this);
}

AForm::~AForm()
{
}

const std::string& AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
	throw GradeTooLowException();
    this->isSigned = true;
}

void AForm::checkExecutability(const Bureaucrat& executor) const
{
    if (!this->isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > this->gradeToExecute)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not sign!");
}


std::ostream& operator<<(std::ostream& lhs, const AForm& form)
{
    lhs << "AForm: " << form.getName() 
	<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< ", Grade to sign: " << form.getGradeToSign()
	<< ", Grade to execute: " << form.getGradeToExecute();
    return (lhs);
}
