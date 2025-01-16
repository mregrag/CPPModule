/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 22:45:23 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/09 16:57:26 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
Array<T>::Array() : array(NULL), _size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    array = new T[n]();
}

template<typename T>
Array<T>::Array(const Array& lhs) : _size(lhs._size)
{
    array = new T[_size]();
    for (unsigned int i = 0; i < _size; i++)
	array[i] = lhs.array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& lhs)
{
    if (this != &lhs)
    {
	if (array)
	    delete[] array;
	_size = lhs._size;
	array = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
	    array[i] = lhs.array[i];
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
	throw OutOfBoundsException();
    return (array[index]);
}

template<typename T>
Array<T>::~Array()
{
    delete[] array;
}


template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
	throw OutOfBoundsException();
    return (array[index]);
}

template<typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return ("Index is out of bounds");
}

