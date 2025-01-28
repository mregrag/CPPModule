/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:55:50 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/27 23:10:22 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void) 
{
    try {
        // Test 1: Default constructor (empty array)
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;

        // Test 2: Constructor with size
	
        Array<int> arr2(-5);
        std::cout << "arr2 size: " << arr2.size() << std::endl;
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
        }

        // Test 3: Copy constructor
        Array<int> arr3(arr2);
        std::cout << "arr3 size (after copy): " << arr3.size() << std::endl;

        // Test 4: Assignment operator
        Array<int> arr4 = arr2;
        std::cout << "arr4 size (after assignment): " << arr4.size() << std::endl;

        // Test 5: Modifying arr2 does not affect arr3 or arr4
        arr2[0] = 99;
        std::cout << "arr2[0] after modification: " << arr2[0] << std::endl;
        std::cout << "arr3[0] (should remain same): " << arr3[0] << std::endl;
        std::cout << "arr4[0] (should remain same): " << arr4[0] << std::endl;

        // Test 6: Bounds checking
        try {
            std::cout << "arr2[10]: " << arr2[10] << std::endl; // This will throw
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test 7: Assigning to an empty array
        Array<int> arr5(0);
        std::cout << "arr5 size: " << arr5.size() << std::endl;
        
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

