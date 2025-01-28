/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:56:07 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/24 18:21:10 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
    Data *data = new Data();
    data->id = 42;
    data->name = "Test Object";

    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "deserialize = " << deserializedData << std::endl;
    std::cout << "&data = " << &data << std::endl;

    if (deserializedData == data)
    {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "Data ID: " << deserializedData->id << std::endl;
        std::cout << "Data Name: " << deserializedData->name << std::endl;
    }
    else
        std::cout << "Deserialization failed." << std::endl;

    return (0);
}

