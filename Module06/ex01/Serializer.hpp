/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:55:57 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/24 18:06:19 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

/*#include <cstdint> // For uintptr_t*/
#include <stdint.h> // For uintptr_t
#include "Data.hpp"

class Serializer
{
    private:
	Serializer();
	Serializer(const Serializer&);
	Serializer& operator=(const Serializer&);
	~Serializer();

    public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
