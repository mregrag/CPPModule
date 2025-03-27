/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:56:07 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/08 16:40:27 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void)
{
    Data original = {42, 'A', true, "Hello World"};

    uintptr_t serialized = Serializer::serialize(&original);

    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Original pointer:   " << &original << std::endl;
    std::cout << "Serialized value:   " << serialized << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;

    std::cout << deserialized->a << std::endl;
    std::cout << deserialized->b << std::endl;
    std::cout << deserialized->c << std::endl;
    std::cout << deserialized->text << std::endl;

    return (0);
}
