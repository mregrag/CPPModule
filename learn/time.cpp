/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:38:56 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/24 06:49:53 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ctime>
#include <stdio.h>
#include <iostream>
#include <iomanip>

int main (void)
{
	time_t timer;
	tm *ltm;

	time(&timer);
	ltm = localtime(&timer);
	std::cout << timer << std::endl;

	std::cout << "year = " << 1900 + ltm->tm_year << std::endl;
	std::cout << "month = " << 1 + ltm->tm_mon << std::endl;
	std::cout << "day = " << ltm->tm_mday << std::endl;
	std::cout << "houre = " << ltm->tm_hour << std::endl;
	std::cout << "minute = " << ltm->tm_min << std::endl;
	std::cout << "second = " << ltm->tm_sec << std::endl;
	
	return (0);
}
