/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:25:07 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/27 19:21:18 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

/*template<typename T>*/
/*class Array*/
/*{*/
/*    private:*/
/*	T* array;*/
/*	unsigned int _size;*/
/**/
/*    public:*/
/*	Array();*/
/**/
/*	Array(unsigned int n);*/
/**/
/*	Array(const Array& lhs);*/
/**/
/*	Array& operator=(const Array& lhs);*/
/**/
/*	~Array();*/
/**/
/*	// Subscript operator*/
/*	T& operator[](unsigned int index);*/
/*	const T& operator[](unsigned int index) const;*/
/**/
/*	// Size getter*/
/*	unsigned int size() const;*/
/**/
/*	// Custom exception class for out of bounds access*/
/*	class OutOfBoundsException : public std::exception{*/
/*	    public:*/
/*		virtual const char* what() const throw();*/
/*	};*/
/*};*/
/**/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // For std::exception
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
	class InvalidArraySizeException : public std::exception {
	    public:
		const char* what() const throw();
	};
	class OutOfBoundsException : public std::exception{
	    public:
		virtual const char* what() const throw();
	};


};

#include "Array.tpp"

#endif

