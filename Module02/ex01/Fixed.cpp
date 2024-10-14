/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 06:36:48 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/12 06:51:44 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): value(0)
{
	std::cout << "Default constrator called" << std::endl;
}

Fixed::Fixed(const int intValue) : value(intValue << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) : value(roundf(floatValue * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->value / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->value >> fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}
