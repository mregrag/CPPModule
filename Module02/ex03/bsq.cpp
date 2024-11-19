/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:53:50 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/17 23:32:10 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed calculArea(Point const& a, Point const& b, Point const& c)
{
	Fixed Area;
	Area = ((b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX())) / Fixed(2);

	if (Area.getRawBits() > 0)
		return (Area);
	return (Area * Fixed(-1));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea = calculArea(a, b, c);

	Fixed area1 = calculArea(point, b, c);
	Fixed area2 = calculArea(a, point, c);
	Fixed area3 = calculArea(a, b, point);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	return ((area1 + area2 + area3) == totalArea);
}
