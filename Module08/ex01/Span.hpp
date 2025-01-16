/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 23:30:11 by mregrag           #+#    #+#             */
/*   Updated: 2024/12/31 23:31:55 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Orthodox Canonical Form
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    // Member functions
    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    // Template function to add range of numbers
    template<typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        unsigned int distance = std::distance(begin, end);
        if (_numbers.size() + distance > _maxSize) {
            throw std::runtime_error("Adding range would exceed maximum size");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }
};

#endif

