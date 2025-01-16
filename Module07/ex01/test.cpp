/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:09:34 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/09 15:25:20 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <iostream>

int sum(int a, int b)
{
    return (a + b);
}

int main(void)
{
    int (*func_ptr)(int, int);

    func_ptr = &sum;

    std::cout << func_ptr(2, 4) << std::endl;

    return (0);
}
