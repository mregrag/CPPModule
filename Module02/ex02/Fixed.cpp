/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:41:27 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/18 23:01:30 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
}

Fixed::Fixed(const int n)
{
	raw = n << Fixed::fractionalBits;
}

Fixed::Fixed(const float n)
{
	raw = roundf(n * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed& rhs)
{
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
		this->raw = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->raw / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->raw >> fractionalBits);
}

std::ostream& operator<<(std::ostream& lhs, const Fixed& rhs)
{
	lhs << rhs.toFloat();
	
	return (lhs);
}

// Comparison operators
bool Fixed::operator>(const Fixed& rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed result;

	result.raw = this->getRawBits() - rhs.getRawBits();
	return (result);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed result;

	result.raw = this->getRawBits() + rhs.getRawBits();
	return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed result;

    result.setRawBits((this->getRawBits() * rhs.getRawBits()) >> fractionalBits);
    return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed result;

	result.setRawBits((this->getRawBits() << fractionalBits) / rhs.getRawBits());
	return (result);
}

// Pre-increment: ++a
Fixed& Fixed::operator++()
{
	this->raw += 1;
	return (*this);
}

// Post-increment: a++
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	++(*this);
	return (temp);
}

// Pre-decrement: --a
Fixed& Fixed::operator--()
{
	this->raw -= 1;
	return (*this);
}

// Post-decrement: a--
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	--(*this); 
	return (temp);
}

// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
