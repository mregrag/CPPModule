/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:53:11 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/10 17:42:40 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		std::string name;
		Weapon&	weapon;
	public:
		HumanA(const std::string& name, Weapon& weapon);
		void attack() const;
};

#endif // !HUMANA_HPP
