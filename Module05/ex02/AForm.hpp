/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:05:34 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/19 17:35:43 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>

class AForm
{
    private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
    public:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& rhs);
	AForm& operator=(const AForm& rhs);
	virtual ~AForm();

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void checkExecutability(const Bureaucrat& executor) const;

	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception {
	    public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	    public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	    public:
		virtual const char* what() const throw();
	};


};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
