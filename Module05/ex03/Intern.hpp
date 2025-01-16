/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:05:06 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/15 14:13:26 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
	AForm* makeShrubberyForm(const std::string& target) const;
	AForm* makeRobotomyForm(const std::string& target) const;
	AForm* makePresidentialPardonForm(const std::string& target) const;

    public:
	Intern();
	Intern(const Intern& rhs);
	Intern& operator=(const Intern& rhs);
	~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);
    class FormNotFoundException : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif


