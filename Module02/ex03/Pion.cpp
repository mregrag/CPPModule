/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pion.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:07:41 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/12 07:10:23 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other)
{
	// Since x and y are const, we can't modify them.
	// In a real scenario, you might want to throw an exception or handle this differently.
	(void)other;
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}
