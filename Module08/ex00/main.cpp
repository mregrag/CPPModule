/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:22:37 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/31 23:28:45 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template<typename T>
void testContainer(T& container, int searchValue, const std::string& containerName) {
    std::cout << "Testing " << containerName << ":" << std::endl;
    std::cout << "Searching for value: " << searchValue << std::endl;

    try {
	typename T::iterator result = easyfind(container, searchValue);
	std::cout << "Value " << *result << " found!" << std::endl;
    }
    catch (const std::exception& e) {
	std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Test with vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    testContainer(vec, 3, "vector");  // Should find
    testContainer(vec, 10, "vector"); // Should not find

    // Test with list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    testContainer(lst, 20, "list");   // Should find
    testContainer(lst, 25, "list");   // Should not find

    // Test with deque
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);

    testContainer(deq, 200, "deque");  // Should find
    testContainer(deq, 500, "deque");  // Should not find

    // Test with empty container
    std::vector<int> emptyVec;
    testContainer(emptyVec, 1, "empty vector");  // Should not find

    return 0;
}

