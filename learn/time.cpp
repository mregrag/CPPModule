/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:38:56 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/22 04:14:03 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ctime>
#include <iostream>
#include <iomanip>

int main (void)
{
	time_t	t;

	std::time(&t);
	
	std::cout << t << std::endl;
	std::cout << "[" << std::put_time(localtime(&t), "%Y%m%d_%H%M%S") << "] ";
	return (0);
}
