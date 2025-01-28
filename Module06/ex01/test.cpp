/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:16:25 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/24 20:06:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <utility>

int main(void)
{
    int a = 65;

    int *p1 = &a;
    char c = reinterpret_cast<char>(&a);

    std::cout << c << std::endl;

    int *p2 = reinterpret_cast<int*>(a);
    std::cout << p2 << std::endl;

    std::cout << reinterpret_cast<long>(p2) << std::endl;

    std::cout << sizeof(int* ) << " " << sizeof(int) << " " << sizeof(long) << std::endl;

    return (0);
}
