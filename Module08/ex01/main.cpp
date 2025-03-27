/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 23:29:46 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/20 22:13:54 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>

int main(void)
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    Span sp3(10000);
    std::list<int> list;

    for (int i = 0; i < 10000; ++i)
        list.push_back(i);

    sp3.addRange(list.begin(), list.end());

    std::cout << "Shortest span of 10000 elements: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span of 10000 elements: " << sp3.longestSpan() << std::endl;

    try 
    {
        sp3.addNumber(42);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    Span sp4(1);
    sp4.addNumber(42);
    try
    {
        sp4.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
