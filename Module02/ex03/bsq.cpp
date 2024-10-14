/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:11:18 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/12 07:11:59 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Function to calculate the area of a triangle
static Fixed area(Point const &a, Point const &b, Point const &c)
{
	return ((b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY())).abs() / 2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Calculate area of triangle ABC
	Fixed areaABC = area(a, b, c);

	// Calculate areas of triangles PBC, PAC, PAB
	Fixed areaPBC = area(point, b, c);
	Fixed areaPAC = area(a, point, c);
	Fixed areaPAB = area(a, b, point);

	// Check if point is on any edge or vertex
	if (areaPBC == 0 || areaPAC == 0 || areaPAB == 0)
	{
		return (false);
	}
	// Check if sum of PBC, PAC, PAB is equal to ABC
	return (areaABC == areaPBC + areaPAC + areaPAB);
}
