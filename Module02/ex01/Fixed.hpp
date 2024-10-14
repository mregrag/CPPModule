/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 06:37:06 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/12 06:45:40 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int value;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed &operator=(const Fixed& other);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif // !FIXED_HPP


