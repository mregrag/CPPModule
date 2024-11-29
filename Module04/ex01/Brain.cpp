/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:09:58 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/28 22:52:29 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain]		Default Constructor Called" << std::endl;
}

Brain::Brain(const Brain& rhs)
{
	std::cout << "[Brain]		Copy Constructor Called" << std::endl;
	*this = rhs;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "[Brain]		copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (size_t i = 0; i < 100 ; i++)
			ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
}

void Brain::setIdea(size_t index, const std::string& idea)
{
	if (index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(size_t index) const
{
	if (index < 100)
		return (ideas[index]);
	return ("");
}
