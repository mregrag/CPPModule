/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:24:18 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/13 21:58:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (this->gradeToSign < 1 || this->gradeToExecute < 1)
	throw GradeTooHighException();
    if (this->gradeToSign > 150 || this->gradeToExecute > 150)
	throw GradeTooLowException();
}

Form::Form(const Form& rhs) : name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute)
{
}

Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs)
	this->isSigned = rhs.isSigned;
    return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
	throw GradeTooLowException();
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low!");
}

std::ostream& operator<<(std::ostream& lhs, const Form& form)
{
    lhs << "Form: " << form.getName() 
	<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< ", Grade to sign: " << form.getGradeToSign()
	<< ", Grade to execute: " << form.getGradeToExecute();
    return (lhs);
}

