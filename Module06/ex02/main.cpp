/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:35:44 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/24 20:14:21 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>

int main(void)
{
    Base* base = generate();

    // Identify the type using a pointer
    std::cout << "Identifying type using a pointer: ";
    identify(base);

    // Identify the type using a reference
    std::cout << "Identifying type using a reference: ";
    identify(*base);

    delete base;

    return (0);
}

