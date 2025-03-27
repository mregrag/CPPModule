/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:41:59 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/22 21:08:57 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	parse_input(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
		_deque = rhs._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

std::string PmergeMe::trim(const std::string& s)
{
	size_t start = s.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ("");
	size_t end = s.find_last_not_of(" \t");
	return (s.substr(start, end - start + 1));
}

void PmergeMe::parse_input(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string arg = trim(std::string(argv[i]));

		std::istringstream iss(arg);
		long num;

		if (!(iss >> num) || !iss.eof() || num < 0 || num > INT_MAX)
			throw std::runtime_error("Error");

		_vector.push_back(static_cast<int>(num));
		_deque.push_back(static_cast<int>(num));
	}
}


void PmergeMe::print_sequence(const std::vector<int> &seq)
{
	for (size_t i = 0; i < seq.size(); ++i)
	{
		if (i != 0)
			std::cout << " ";
		std::cout << seq[i];
	}
	std::cout << std::endl;
}

void PmergeMe::binary_insert(std::vector<int> &arr, int value)
{
	std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
	arr.insert(pos, value);
}

void PmergeMe::binary_insert(std::deque<int> &arr, int value)
{
	std::deque<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
	arr.insert(pos, value);
}

void PmergeMe::sortAndDisplay()
{
	std::cout << "Before: ";
	print_sequence(_vector);

	clock_t start = clock();
	sortVector();
	clock_t end = clock();
	double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	sortDeque();
	end = clock();
	double deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	print_sequence(_vector);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << vector_time << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << deque_time << " us" << std::endl;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t m)
{
	std::vector<size_t> order;

	if (m == 0)
		return order;
	// Jacobsthal sequence t_k = (2^(k+1) + (-1)^k) / 3
	std::vector<size_t> t;
	t.push_back(1); 
	t.push_back(1);
	while (true)
	{
		size_t k = t.size();
		size_t next_t = ((1 << (k + 1)) + ((k % 2 == 0) ? 1 : -1)) / 3;
		if (next_t > m)
			break;
		t.push_back(next_t);
	}
	std::vector<bool> used(m, false);
	for (size_t i = t.size() - 1; i > 0; --i)  
		for (size_t j = t[i]; j > t[i - 1]; --j)
		{
			if (j - 1 < m && !used[j - 1])
			{
				order.push_back(j - 1);
				used[j - 1] = true;
			}
		}
	for (size_t j = 0; j < m; ++j)
		if (!used[j])
			order.push_back(j);
	return (order);
}

void PmergeMe::sortVector()
{
	if (_vector.size() <= 1)
		return;

	bool has_odd_element = (_vector.size() % 2 != 0);
	int odd_element = has_odd_element ? _vector.back() : 0;

	if (has_odd_element)
		_vector.pop_back();

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < _vector.size(); i += 2)
		pairs.push_back(std::make_pair(std::max(_vector[i], _vector[i + 1]), std::min(_vector[i], _vector[i + 1])));

	std::vector<int> larger_elements;
	for (size_t i = 0; i < pairs.size(); ++i)
		larger_elements.push_back(pairs[i].first);

	_vector = larger_elements; 
	sortVector();
	std::vector<int> main = _vector;

	std::vector<int> pending;
	for (size_t i = 0; i < pairs.size(); ++i)
		pending.push_back(pairs[i].second);

	if (!pending.empty())
		binary_insert(main, pending[0]); 

	if (pending.size() > 1)
	{
		std::vector<size_t> insertion_sequence = generateInsertionOrder(pending.size());
		for (size_t i = 0; i < insertion_sequence.size(); ++i)
		{
			int idx = insertion_sequence[i];
			if (idx > 0 && idx < (int)pending.size())
				binary_insert(main, pending[idx]);
		}
	}
	if (has_odd_element)
		binary_insert(main, odd_element);
	_vector = main;
}

void PmergeMe::sortDeque()
{
	if (_deque.size() <= 1)
		return;

	bool has_odd_element = (_deque.size() % 2 != 0);
	int odd_element = has_odd_element ? _deque.back() : 0;

	if (has_odd_element)
		_deque.pop_back();

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < _deque.size(); i += 2)
		pairs.push_back(std::make_pair(std::max(_deque[i], _deque[i + 1]), std::min(_deque[i], _deque[i + 1])));

	std::deque<int> larger_elements;
	for (size_t i = 0; i < pairs.size(); ++i)
		larger_elements.push_back(pairs[i].first);

	_deque = larger_elements;
	sortDeque();
	std::deque<int> main = _deque;

	std::vector<int> pending;
	for (size_t i = 0; i < pairs.size(); ++i)
		pending.push_back(pairs[i].second);

	if (!pending.empty())
		binary_insert(main, pending[0]); 

	if (pending.size() > 1)
	{
		std::vector<size_t> insertion_sequence = generateInsertionOrder(pending.size());

		for (size_t i = 0; i < insertion_sequence.size(); ++i)
		{
			int idx = insertion_sequence[i];
			if (idx < (int)pending.size())
				binary_insert(main, pending[idx]);
		}
		if (has_odd_element)
			binary_insert(main, odd_element);
	}
	_deque = main;
}
