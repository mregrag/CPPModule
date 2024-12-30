/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:10:08 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/11 23:43:21 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
    private:
	std::string ideas[100];
    public:
	Brain();
	Brain(const Brain& rhs);
	Brain& operator=(const Brain& rhs);
	~Brain();

	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;
};

#endif
