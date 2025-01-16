/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:50:12 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/08 18:30:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T &a, T &b)
{
    if (&a == &b)
	return;
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T &min(const T &a, const T &b)
{
    if (a < b)
	return (a);
    return (b);
}

template <typename T>
const T &max(const T &a, const T &b)
{
    if (a > b)
	return (a);
    return (b);
}

