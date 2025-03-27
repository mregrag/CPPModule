/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:52:47 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/13 17:52:48 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T &x)
{
    std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
    x++;
}

template <typename T>
void to_upper(T &c)
{
    c = std::toupper(static_cast<unsigned char>(c));
}

int main(void)
{
    int arrInt[] = {1, 2, 3, 4, 5};
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), ::print);

    std::cout << "-------------------------------------------" << std::endl;
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), ::increment);
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), ::print);
    std::cout << "-------------------------------------------" << std::endl;

    char char_arr[] = {'a', 'b', 'c', 'd'};
    iter(char_arr, 4, print);

    std::cout << "-------------------------------------------" << std::endl;
    iter(char_arr, 4, to_upper);
    iter(char_arr, 4, print);

    return (0);
}
