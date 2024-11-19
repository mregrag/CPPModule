/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:51:42 by mregrag           #+#    #+#             */
/*   Updated: 2024/11/17 23:34:39 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 5);

    Point inside(5, 2);

    Point outside(-5, 5);
    Point onEdge(3, 0);
    Point vertex(5, 5);

    std::cout << "Point inside triangle: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Point outside triangle: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "Point on edge: " << (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;
    std::cout << "Point on vertex: " << (bsp(a, b, c, vertex) ? "true" : "false") << std::endl;

    return (0);
}
