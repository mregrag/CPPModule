/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:25:07 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/13 17:33:28 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>


#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
template <typename T>
class Array 
{
    private:
	T* _array;
	unsigned int _size;

    public:
	Array();
	Array(unsigned int n);
	Array(const Array<T>& rhs);

	~Array();

	Array<T>& operator=(const Array<T>& rhs);

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	unsigned int size() const;

	class OutOfBoundsException : public std::exception{
	    public:
		virtual const char* what() const throw();
	};


};

#include "Array.tpp"

#endif

