/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:53:40 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/11 21:33:31 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal 
{
    protected:
	std::string type;
    public:
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& rhs);
	Animal& operator=(const Animal& rhs);
	virtual ~Animal();

	virtual void makeSound() const;
	std::string const& getType() const;
};

#endif
