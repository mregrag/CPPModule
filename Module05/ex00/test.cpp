/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:49:47 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/16 16:10:48 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <new>
#include <stdexcept>

void allocator(int size)
{
    int *p = new int[size];
}

double devide(int a, int b)
{
    if (b == 0)
	throw std::runtime_error("Division by zero is not allowed !");
    return (static_cast<double>(a) / b);
}

int main()
{
    try
    {
	double result = devide(2, 0);
	std::cout << "Result : " << result << std::endl;
    } 
    catch (const std::runtime_error& e)
    {
    
	std::cout << "Error : " << e.what() << std::endl;
    
    }
    return (0);
}

/*try*/
/*{*/
/*    allocator(-1);*/
/*}*/
/**/
/*catch (std::bad_alloc& e)*/
/*{*/
/*    std::cout << "Error : " << e.what()<< std::endl;*/
/*}*/
/**/
/*catch (std::runtime_error& e)*/
/*{*/
/*    std::cout << "Error : " << e.what()<< std::endl;*/
/*}*/
