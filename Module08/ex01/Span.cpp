/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 23:30:01 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/31 23:33:24 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::runtime_error("Cannot add number: Span is full");
    }
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw std::runtime_error("Cannot find span: Need at least 2 numbers");
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
        minSpan = std::min(minSpan, span);
    }
    
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw std::runtime_error("Cannot find span: Need at least 2 numbers");
    }

    std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());
    
    return static_cast<unsigned int>(*max - *min);
}

