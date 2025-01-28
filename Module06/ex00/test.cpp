/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:39:00 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/28 00:26:41 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>



#include <iostream>
#include <climits> // For INT_MAX

int main() {
    float maxInt = FLT_MAX + 10; // Maximum value of an int
    float maxIntAsFloat = static_cast<float>(maxInt + 10); // Cast to float

    std::cout << "Maximum int: " << maxInt << std::endl;
    std::cout << "Maximum int as float: " << maxIntAsFloat << std::endl;

    return 0;
}

