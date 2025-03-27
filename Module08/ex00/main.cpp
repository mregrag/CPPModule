/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:22:37 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/20 22:09:04 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> vec(1);
	std::cout << vec.size() << std::endl;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 0);
		std::cout << "Value found in vector: " << *it << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	try 
	{
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Value found in list: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
