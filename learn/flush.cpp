/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:50:44 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/25 05:39:02 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

int main()
{
    std::cout << "Hello" << std::flush; // Flushes the output immediately
    /*std::this_thread::sleep_for(std::chrono::seconds(2)); // Waits for 2 seconds*/

    std::cout << ", World!" << std::endl; // `std::endl` also flushes the output
    return 0;
}

