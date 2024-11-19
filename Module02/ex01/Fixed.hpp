/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:26:00 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/18 22:52:33 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int raw;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& rhs);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		float toFloat(void) const;
		int toInt(void) const;
		void setRawBits(const int raw);
		int getRawBits(void) const;
};

std::ostream& operator<<(std::ostream& lhs, const Fixed& rhs);

#endif
