/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:47:02 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/12 14:48:15 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
	AMateria* materias[4];
    public:
	MateriaSource();
	MateriaSource(const MateriaSource& rhs);
	MateriaSource& operator=(const MateriaSource& rhs);
	~MateriaSource();

	void learnMateria(AMateria* m);
	AMateria* createMateria(const std::string& type);
};

#endif

