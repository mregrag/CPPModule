/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 23:30:11 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/20 20:33:42 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <climits>

class Span
{
    private:
	unsigned int capacity;
	std::vector<int> numbers;

    public:
	Span();
	Span(unsigned int N);
	Span(const Span& rhs);
	Span& operator=(const Span& rhs);
	~Span();

	void addNumber(int number);

	template <typename Iter>
	    void addRange(Iter start, Iter end)
	    {
		if (this->numbers.size() + std::distance(start, end) > this->capacity)
		    throw std::runtime_error("Error: Not enough space to add all numbers");
		this->numbers.insert(this->numbers.end(), start, end);
	    }
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif
