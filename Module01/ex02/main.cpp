/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:39:31 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/09 23:50:37 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main (void)
{
	std::string string = "HI THIS IS BRAIN";

	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "The value of the string variable : " << string << &string << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << &stringREF << std::endl;

	return (0);
}
