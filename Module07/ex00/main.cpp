/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:50:58 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/27 17:42:10 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "whatever.hpp"

class Number
{
    private:
	int value;
    public:
	Number();
	Number(int value): value(value){};
	Number(const Number& rhs): value(rhs.value){};
	Number& operator=(const Number& rhs)
	{
	    if (this->value != rhs.value)
		this->value = rhs.value;
	    return (*this);
	}

	int getvalue() const
	{
	    return (this->value);
	}
};

std::ostream& operator<<(std::ostream& lhs, const Number& rhs)
{
    lhs << rhs.getvalue();
    return (lhs);
}

int main()
{
    int a = 2;
    int b = 3;

    Number x = 10;
    Number y = 20;

    ::swap(x, y);
    std::cout << "x = : " << x << std::endl;
    std::cout << "y = : " << y << std::endl;


    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "string1";
    std::string d = "string2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    return 0;
}

