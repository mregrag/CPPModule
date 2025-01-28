/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:52:47 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/27 18:01:13 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "iter.hpp"

template <typename T>
void print(T &x)
{
    std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
    x++;
}

class Number
{
    private:
	int value;
    public:
	Number() : value(42){}
	int getNumber() const
	{
	    return (value);
	}
	Number operator++(int)
	{
	    Number temp(*this);
	    this->value += 1;
	    return (temp);
	}

};

std::ostream& operator<<(std::ostream& lhs, Number const& rhs)
{
    lhs << rhs.getNumber();
    return (lhs);
}

int main()
{
    int arrInt[] = {1, 2, 3, 4, 5};
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), ::print<int>);
    std::cout << std::string(20, '-') << std::endl;
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), ::increment);
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), ::print);
    std::cout << std::string(20, '-') << std::endl;


    std::string arrStr[] = {"Hello", "1337", "World"};
    iter(arrStr, sizeof(arrStr)/sizeof(arrStr[0]), ::print);
    std::cout << std::string(20, '-') << std::endl;

    Number arrayNumber[3];
    iter(arrayNumber, sizeof(arrayNumber) / sizeof(arrayNumber[0]), ::print);
    std::cout << std::string(20, '-') << std::endl;
    iter(arrayNumber, sizeof(arrayNumber) / sizeof(arrayNumber[0]), ::increment);
    iter(arrayNumber, sizeof(arrayNumber) / sizeof(arrayNumber[0]), ::print);


    return (0);

}
