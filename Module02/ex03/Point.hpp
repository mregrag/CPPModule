/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:07:26 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/12 07:10:39 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();  // Default constructor
		Point(const float x, const float y);  // Float constructor
		Point(const Point &other);  // Copy constructor
		Point &operator=(const Point &other);  // Copy assignment operator
		~Point();  // Destructor

		Fixed getX() const;
		Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
