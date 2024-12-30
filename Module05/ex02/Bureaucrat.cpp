/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:06:28 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/29 20:36:50 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : name(rhs.name), grade(rhs.grade)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
        grade = rhs.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

// Exception messages
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

// Grade modification methods
void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() 
                 << " because " << e.what() << std::endl;
    }
}

// Overload of insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
