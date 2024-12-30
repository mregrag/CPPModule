/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:17:59 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/10 15:00:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& rhs);
		AMateria& operator=(const AMateria& rhs);

		virtual ~AMateria();
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		std::string const& getType() const;
};

#endif
