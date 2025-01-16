/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:55:50 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/31 22:58:08 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    try 
    {
        // Test empty array
        std::cout << "Testing empty array:" << std::endl;
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;

        // Test array with size
        std::cout << "\nTesting array with size:" << std::endl;
        Array<int> numbers(-1);
        std::cout << "Array size: " << numbers.size() << std::endl;
        
	/*       // Fill array and display*/
	/*       for (unsigned int i = 0; i < numbers.size(); i++)*/
	/*           numbers[i] = i * 2;*/
	/**/
	/*       std::cout << "Array contents: ";*/
	/*       for (unsigned int i = 0; i < numbers.size(); i++)*/
	/*           std::cout << numbers[i] << " ";*/
	/**/
	/*       std::cout << std::endl;*/
	/**/
	/*       // Test copy constructor*/
	/*       std::cout << "\nTesting copy constructor:" << std::endl;*/
	/*       Array<int> copy(numbers);*/
	/*       std::cout << "Original array: ";*/
	/*       for (unsigned int i = 0; i < numbers.size(); i++)*/
	/*           std::cout << numbers[i] << " ";*/
	/**/
	/*       std::cout << std::endl;*/
	/**/
	/*       // Modify copy*/
	/*       copy[2] = 99;*/
	/*       std::cout << "Modified copy: ";*/
	/*       for (unsigned int i = 0; i < copy.size(); i++)*/
	/*           std::cout << copy[i] << " ";*/
	/**/
	/*       std::cout << std::endl;*/
	/**/
	/*       std::cout << "Original array (unchanged): ";*/
	/*       for (unsigned int i = 0; i < numbers.size(); i++)*/
	/*           std::cout << numbers[i] << " ";*/
	/**/
	/*       std::cout << std::endl;*/
	/**/
	/*       // Test assignment operator*/
	/*       std::cout << "\nTesting assignment operator:" << std::endl;*/
	/*       Array<int> assigned = numbers;*/
	/*       assigned[0] = 100;*/
	/**/
	/*       std::cout << "Assigned and modified array: ";*/
	/*       for (unsigned int i = 0; i < assigned.size(); i++)*/
	/*           std::cout << assigned[i] << " ";*/
	/**/
	/*       std::cout << std::endl;*/
	/**/
	/*       // Test out of bounds exception*/
	/*       std::cout << "\nTesting out of bounds exception:" << std::endl;*/
	/*       try */
	/*{*/
	/*           numbers[10] = 0;*/
	/*       }*/
	/*       catch (const std::exception& e)*/
	/*{*/
	/*           std::cout << "Exception caught: " << e.what() << std::endl;*/
	/*       }*/
	/**/
	/*       // Test with different type*/
	/*       std::cout << "\nTesting with strings:" << std::endl;*/
	/*       Array<std::string> strings(3);*/
	/*       strings[0] = "Hello";*/
	/*       strings[1] = "World";*/
	/*       strings[2] = "!";*/
	/**/
	/*       for (unsigned int i = 0; i < strings.size(); i++)*/
	/*           std::cout << strings[i] << " ";*/
	/**/
	/*       std::cout << std::endl;*/

    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return (0);
}

