/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:53:27 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/09 15:35:14 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void iter(T *array, size_t length, void (*func)(T &))
{
    if (!array || !func)
	return;
    for (size_t i = 0; i < length; ++i)
	func(array[i]);
}
