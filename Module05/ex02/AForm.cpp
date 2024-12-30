/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:05:17 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/29 20:24:23 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Exception messages
AForm::AForm() : name("Default AForm"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    this->isSigned = false;
    if (gradeToSign < 1 || gradeToExecute < 1)
	throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
	throw GradeTooLowException();
}

AForm::AForm(const AForm& rhs) : name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& rhs)
{
    if (this != &rhs)
	isSigned = rhs.isSigned;
    return (*this);
}

AForm::~AForm()
{
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade is too low!");
}

const std::string& AForm::getName() const
{
    return (name);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
	throw GradeTooLowException();
    isSigned = true;
}

void AForm::checkExecutability(const Bureaucrat& executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "AForm: " << form.getName() 
	<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< ", Grade to sign: " << form.getGradeToSign()
	<< ", Grade to execute: " << form.getGradeToExecute();
    return (os);
}
