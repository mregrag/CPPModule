/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:41:09 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/08 23:50:02 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{

	Fixed a;
	++a;
	std::cout << a << std::endl;

	/*Fixed const b(Fixed(5.05f) * Fixed(2));*/
	/**/
	/*std::cout << a << std::endl;*/
	/*std::cout << ++a << std::endl;*/
	/*std::cout << a << std::endl;*/
	/*std::cout << a++ << std::endl;*/
	/**/
	/*std::cout << a << std::endl;*/
	/*std::cout << b << std::endl;*/
	/**/
	/*std::cout << Fixed::max(a, b) << std::endl;*/

	return (0);
}

