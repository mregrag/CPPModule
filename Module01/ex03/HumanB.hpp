/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:38:03 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/30 18:36:09 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string name;
		Weapon*	weapon;
	public:
		HumanB(const std::string& name);
		~HumanB();
		void	attack();
		void setWeapon(Weapon &weapon);
};

#endif

