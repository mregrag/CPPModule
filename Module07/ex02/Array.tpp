/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 22:45:23 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/13 17:36:07 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    if (n == 0)
	this->_array = NULL;
    this->_array = new T[this->_size];
}

template <typename T>
Array<T>::Array(const Array<T>& rhs) : _array(NULL), _size(0)
{
    *this = rhs;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if (this != &rhs)
    {
        if (this->_array)
            delete[] this->_array;
        this->_size = rhs._size;
        if (this->_size > 0)
	{
            this->_array = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; ++i)
                this->_array[i] = rhs._array[i];
        }
	else
            _array = NULL;
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size)
        throw OutOfBoundsException();
    return (this->_array[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_size)
        throw OutOfBoundsException();
    return (this->_array[index]);
}

template <typename T>
Array<T>::~Array() 
{
    if (this->_array)
        delete[] this->_array;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->_size);
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return ("Array index out of bounds exception occurred.");
}

#endif
