/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/11 23:43:28 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
	Brain* brain;
    public:
	Dog();
	Dog(const std::string& type);
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);
	~Dog();

	void makeSound() const;
	Brain* getBrain() const;
};

#endif
