/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:38:34 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/31 12:27:29 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class	Weapon 
{
	private:
		std::string type;
	public:
		Weapon(const std::string& type);
		~Weapon();
		const std::string& getType(void) const;
		void setType(const std::string& type);
};

#endif
