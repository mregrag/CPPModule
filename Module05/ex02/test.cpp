/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:46:43 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/14 20:51:53 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ctime>
#include <cstdlib>


int main(void)
{

    srand(time(0));
    std::cout << rand() % 2 << std::endl;

    /*std::cout << "max_rand : " << RAND_MAX << std::endl;*/

	/*   for (int i = 0; i < 3; i++)*/
	/*std::cout << rand() << " ";*/
    return (0);
}
