/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/11 21:31:17 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
	Dog();
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);
	~Dog();

	void makeSound() const;
};

#endif
