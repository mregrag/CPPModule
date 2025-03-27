/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:32:18 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/22 21:23:12 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& rhs) : stack(rhs.stack)
{
}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
		stack = rhs.stack;
	return (*this);
}

RPN::~RPN()
{
}

bool RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(char op)
{
	if (stack.size() < 2)
		throw std::runtime_error("Error");

	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();

	switch (op)
	{
		case '+': stack.push(a + b); break;
		case '-': stack.push(a - b); break;
		case '*': stack.push(a * b); break;
		case '/':
			  if (b == 0)
				  throw std::runtime_error("Error: division by zero");
			  stack.push(a / b); break;
		default: throw std::runtime_error("Error");
	}
}

int RPN::calculate(const std::string& input)
{
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
			stack.push(token[0] - 48);
		else if (token.length() == 1 && isOperator(token[0])) 
			performOperation(token[0]);
		else 
			throw std::runtime_error("Error");

	}

	if (stack.size() != 1)
		throw std::runtime_error("Error");

	int result = stack.top();
	stack.pop();

	return (result);
}
