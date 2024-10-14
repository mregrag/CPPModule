/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 04:54:10 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/12 05:34:43 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int value;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed& other);
		~Fixed();

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};
#endif // !FIXED_HPP
