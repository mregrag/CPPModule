/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:23:13 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/14 17:37:12 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
    private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
    public:
	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& rhs);
	Form& operator=(const Form& rhs);
	~Form();

	class GradeTooHighException : public std::exception {
	    public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	    public:
		const char* what() const throw();
	};

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);


};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
