/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:53:27 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/27 17:31:54 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void iter(T *array, int length, void (*func)(T &))
{
    if (!array || !func)
	return;
    for (int i = 0; i < length; ++i)
	func(array[i]);
}
