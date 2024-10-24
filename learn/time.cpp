/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:38:56 by mregrag           #+#    #+#             */
/*   Updated: 2024/10/23 03:33:08 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ctime>
#include <iostream>
#include <iomanip>

class Rectangle
{
    private:
        int width;
        int height;
    public:
	typedef Rectangle Rect;
        Rectangle(int w, int h) : width(w), height(h) {}
        int getArea() { return width * height; }
};

// Creating a typedef for Rectangle class

int main() {
    // Now we can use 'Rect' instead of 'Rectangle'
	Rectangle::Rect r1(5, 3);    // Same as Rectangle r1(5, 3);
    
    return 0;
}
