/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:52:47 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/09 16:43:42 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <string>
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
	int n;
    public:
	Number() : n(42){}
	int getNumber() const
	{
	    return (n);
	}
	void increment()
	{
	    n++;
	}
	Number operator++(int)
	{
	    Number temp(*this);
	    this->n += 1;
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
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), print);
    std::cout << std::string(20, '-') << std::endl;
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), increment);
    iter(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), print);
    std::cout << std::string(20, '-') << std::endl;


    //Test with string
    std::string arrStr[] = {"hello", "42", "school"};
    iter(arrStr, sizeof(arrStr)/sizeof(arrStr[0]), print);
    std::cout << std::string(20, '-') << std::endl;

    //Test with class
    Number number_array[3];
    iter(number_array, sizeof(number_array) / sizeof(number_array[0]), print);
    std::cout << std::string(20, '-') << std::endl;
    iter(number_array, sizeof(number_array) / sizeof(number_array[0]), increment<Number>);
    iter(number_array, sizeof(number_array) / sizeof(number_array[0]), print);


    return (0);

}
