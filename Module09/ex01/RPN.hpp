/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:32:28 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/21 02:03:29 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <exception>
#include <sstream>
#include <iostream>

class RPN 
{
	private:
		std::stack<int> stack;

		bool isOperator(char c) const;
		void performOperation(char op);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int calculate(const std::string& input);
};

#endif
