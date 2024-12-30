/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:38:48 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/11 23:44:14 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal 
{
    protected:
	std::string type;
    public:
	AAnimal();
	AAnimal(const std::string& type);
	AAnimal(const AAnimal& rhs);
	AAnimal& operator=(const AAnimal& rhs);
	virtual ~AAnimal();

	std::string const& getType() const;
	virtual void makeSound() const = 0;
};

#endif
