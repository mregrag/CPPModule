/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 23:30:01 by mregrag           #+#    #+#             */
/*   Updated: 2025/02/20 20:41:12 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : capacity(0)
{
}

Span::Span(unsigned int N) : capacity(N)
{
}

Span::Span(const Span& rhs) : capacity(rhs.capacity), numbers(rhs.numbers)
{
}

Span& Span::operator=(const Span& rhs)
{
    if (this != &rhs)
    {
    	this->capacity = rhs.capacity;
	this->numbers = rhs.numbers;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (this->numbers.size() >= this->capacity)
	throw std::runtime_error("Error: Span is full");
    this->numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (this->numbers.size() < 2)
        throw std::runtime_error("Error: Not enough elements");

    std::vector<int> sorted(this->numbers);
    std::sort(sorted.begin(), sorted.end());

    unsigned int min = UINT_MAX;
     for (size_t i = 1; i < sorted.size(); i++)
        min = std::min(min, static_cast<unsigned int>(sorted[i] - sorted[i - 1]));
    return (min);
}

unsigned int Span::longestSpan() const
{
    if (this->numbers.size() < 2)
	throw std::runtime_error("Error: Not enough elements");

    std::vector<int> sorted(this->numbers);
    std::sort(sorted.begin(), sorted.end());

    return (sorted.back() - sorted.front());
}
