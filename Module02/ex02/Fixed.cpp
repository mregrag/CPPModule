/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 06:54:48 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/12 07:04:33 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): value(0)
{
}

Fixed::Fixed(const int intValue) : value(intValue << fractionalBits)
{
}

Fixed::Fixed(const float floatValue) : value(roundf(floatValue * (1 << fractionalBits)))
{
}

Fixed::Fixed(const Fixed& other)
{
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
}

int Fixed::getRawBits(void) const 
{
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

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->value != other.value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment/decrement operators
Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Static member functions
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
