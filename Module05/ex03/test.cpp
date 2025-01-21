/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:30:10 by mregrag           #+#    #+#             */
/*   Updated: 2025/01/19 19:21:44 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Calculator
{
    private:

    public:
	void add(int x, int y)
	{
	    std::cout << "sum : " << x + y << std::endl;
	}

	void sub(int x, int y)
	{
	    std::cout << "sub :" << x - y << std::endl;
	}
	void mul(int x, int y)
	{
	    std::cout << "mul :" << x * y << std::endl;
	}

	void div(int x, int y)
	{
	    std::cout << "div :" << x / y << std::endl;
	}

	void result(const std::string& operat, int x, int y)
	{
	    std::string op[4] = {"add", "sub", "mul", "div"};
	     void (Calculator::*calcul[4])(int, int) = {
		 &Calculator::add,
		 &Calculator::sub,
		 &Calculator::mul,
		 &Calculator::div,
	     };

	     for (int i = 0; i < 4; i++)
	     {
		 if (operat == op[i])
		 {
		     (this->*calcul[i])(x, y);
		     break;
		 }
	     }
	}
};

int main(void)
{

    Calculator calc;

    void (Calculator::*ptr)(int, int);
    (calc.*ptr)(2, 3);

    calc.result("add", 3, 3);
    calc.result("sub", 3, 3);
    calc.result("div", 3, 3);
    calc.result("mul", 3, 3);
    return (0);
}
