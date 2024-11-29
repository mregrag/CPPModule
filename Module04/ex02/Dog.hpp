/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 22:50:47 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& rhs);
		Dog& operator=(const Dog& rhs);
		~Dog();

		std::string getType() const;
		void makeSound() const;
		Brain* getBrain() const;
};

#endif
