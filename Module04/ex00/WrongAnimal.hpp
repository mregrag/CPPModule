/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:55:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/11 21:31:29 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal 
{
    protected:
	std::string type;
    public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& rhs);
	WrongAnimal& operator=(const WrongAnimal& rhs);
	~WrongAnimal();

	std::string getType() const;
	void makeSound() const;
};

#endif
