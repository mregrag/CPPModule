/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 23:29:46 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/31 23:31:40 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

void testBasicFunctionality() {
    std::cout << "Basic functionality test:" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testLargeNumbers() {
    std::cout << "\nLarge numbers test (10000 numbers):" << std::endl;
    Span sp = Span(10000);
    std::srand(std::time(0));
    
    // Fill using addRange with vector
    std::vector<int> numbers;
    for (int i = 0; i < 10000; ++i) {
        numbers.push_back(rand());
    }
    
    try {
        sp.addRange(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testExceptions() {
    std::cout << "\nException tests:" << std::endl;
    
    // Test adding to full span
    Span sp1 = Span(1);
    try {
        sp1.addNumber(1);
        sp1.addNumber(2);  // Should throw
    }
    catch (const std::exception& e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }
    
    // Test span with insufficient numbers
    Span sp2 = Span(5);
    try {
        sp2.shortestSpan();  // Should throw
    }
    catch (const std::exception& e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }
}

void testDifferentContainers() {
    std::cout << "\nTesting with different containers:" << std::endl;
    Span sp = Span(5);
    
    // Test with list
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    
    try {
        sp.addRange(lst.begin(), lst.end());
        std::cout << "Successfully added list range" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    testBasicFunctionality();
    testLargeNumbers();
    testExceptions();
    testDifferentContainers();
    
    return 0;
}
