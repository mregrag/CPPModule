/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:26:32 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/18 22:52:36 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	raw = n << Fixed::fractionalBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	raw = roundf(n * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->raw = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->raw);
}

void Fixed::setRawBits(const int raw)
{
	this->raw = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->raw / (1 << Fixed::fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->raw >> Fixed::fractionalBits);
}

std::ostream& operator<<(std::ostream& lhs, const Fixed& rhs)
{
	lhs.operator<<(rhs.toFloat());

	return (lhs);
}
