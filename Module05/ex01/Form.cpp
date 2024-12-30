/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:24:18 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/29 19:39:34 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"

// Exception messages
Form::Form() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    this->isSigned = false;
    if (gradeToSign < 1 || gradeToExecute < 1)
	throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
	throw GradeTooLowException();
}

Form::Form(const Form& rhs) : name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute)
{
}

Form& Form::operator=(const Form& rhs)
{
    if (this != &rhs)
	isSigned = rhs.isSigned;
    return (*this);
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low!");
}

std::string Form::getName() const
{
    return (name);
}

bool Form::getIsSigned() const
{
    return (isSigned);
}

int Form::getGradeToSign() const
{
    return (gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
	throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() 
	<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< ", Grade to sign: " << form.getGradeToSign()
	<< ", Grade to execute: " << form.getGradeToExecute();
    return (os);
}

// Bureaucrat implementation of signForm
void Bureaucrat::signForm(Form& form)
{
    try
    {
	form.beSigned(*this);
	std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (Form::GradeTooLowException& e)
    {
	std::cout << name << " couldn't sign " << form.getName() 
	    << " because " << e.what() << std::endl;
    }
}
