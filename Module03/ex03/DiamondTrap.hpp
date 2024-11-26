/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 06:35:00 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/26 00:34:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string&ame);
		DiamondTrap(const DiamondTrap& rhs);
		DiamondTrap& operator=(const DiamondTrap& rhs);
		~DiamondTrap();

		void attack(const std::string& target);
		void whoAmI();
};

#endif
