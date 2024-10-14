/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:25:55 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/10 19:03:06 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl harl;

	std::cout << "Complaints at different levels:" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	std::cout << "\nUnknown level test:" << std::endl;
	harl.complain("UNKNOWN");

	return 0;
}

