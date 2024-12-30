/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:09:58 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/12 20:22:07 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[Brain]		Default Constructor Called" << std::endl;
    for (int i = 0; i < 100 ; i++)
	this->ideas[i] = "No Idea";
}

Brain::Brain(const Brain& rhs)
{
    std::cout << "[Brain]		Copy Constructor Called" << std::endl;
    *this = rhs;
}

Brain& Brain::operator=(const Brain& rhs)
{
    std::cout << "[Brain]		Copy Assignment Operator Called" << std::endl;
    if (this != &rhs)
    {
	for (int i = 0; i < 100 ; i++)
	    this->ideas[i] = rhs.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "[Brain]		Destructor Called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
	return (this->ideas[index]);
    return ("");
}
