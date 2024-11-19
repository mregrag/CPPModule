/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:09:30 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/18 22:51:42 by mregrag          ###   ########.fr       */
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
		Fixed(const Fixed& rhs);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(const int raw);
};

#endif
