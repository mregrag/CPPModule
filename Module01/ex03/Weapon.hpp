/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:52:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/14 04:12:21 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(const std::string& type);
		const std::string& getType() const;
		void	setType(const std::string& newType);
};
#endif
