/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:50:12 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/12 16:12:05 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

template <typename T>const T &max(const T &a, const T &b)
{
    if (a > b)
	return (a);
    return (b);
}
