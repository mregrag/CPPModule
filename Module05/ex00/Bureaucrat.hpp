/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:27:44 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/16 21:37:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCTRAT_HPP
# define BUREAUCTRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
	const std::string name;
	int grade;

    public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& rhs);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	    public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	    public:
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
