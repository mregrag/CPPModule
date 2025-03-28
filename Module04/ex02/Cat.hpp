/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:54:33 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/11 23:43:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
	Brain* brain;
    public:
	Cat();
	Cat(const std::string& type);
	Cat(const Cat& rhs);
	Cat& operator=(const Cat& rhs);
	~Cat();

	void makeSound() const;
	Brain* getBrain() const;
};

#endif
