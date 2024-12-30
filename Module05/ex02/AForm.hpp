/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:05:34 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/29 20:16:39 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

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
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
	    virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	    virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	    virtual const char* what() const throw();
	};

    protected:
	void checkExecutability(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
