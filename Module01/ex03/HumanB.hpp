/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:54:23 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/10 16:49:51 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
	private:
		std::string name;
		Weapon	*weapon;
	public:
		HumanB(const std::string& name);
		void attack() const;
		void setWeapon(Weapon &weapon);
};

#endif // !HUMANA_HPP

