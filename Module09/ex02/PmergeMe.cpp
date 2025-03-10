/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:41:59 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/10 21:20:10 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <stdexcept>

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
		original = rhs.original;
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

		if (!arg.empty() && arg[0] == '+')
			arg.erase(0, 1);
		std::istringstream iss(arg);
		long num;

		if (!(iss >> num) || !iss.eof() || num < 0 || num > INT_MAX)
			throw std::runtime_error("Error");

		original.push_back(static_cast<int>(num));
	}

	_vector = original;
	_deque.assign(original.begin(), original.end());
}

void PmergeMe::sort_and_display()
{
	std::cout << "Before: ";
	print_sequence(original);

	clock_t start = clock();
	ford_johnson_sort_vector(_vector);
	clock_t end = clock();
	double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	ford_johnson_sort_deque(_deque);
	end = clock();
	double deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	print_sequence(_vector);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << vector_time << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << deque_time << " us" << std::endl;
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

void PmergeMe::merge_pairs(std::vector<ElementPair> &pairs, int left, int mid, int right)
{
	std::vector<ElementPair> temp;
	int i = left, j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (pairs[i].first <= pairs[j].first)
			temp.push_back(pairs[i++]);
		else
			temp.push_back(pairs[j++]);
	}

	while (i <= mid)
		temp.push_back(pairs[i++]);

	while (j <= right)
		temp.push_back(pairs[j++]);

	for (size_t k = 0; k < temp.size(); ++k)
		pairs[left + k] = temp[k];
}

void PmergeMe::recursive_sort(std::vector<ElementPair> &pairs, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	recursive_sort(pairs, left, mid);
	recursive_sort(pairs, mid + 1, right);

	merge_pairs(pairs, left, mid, right);
}


std::vector<int> PmergeMe::generateJacobsthalNumbers(int n)
{
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0); // J(0) = 0 (not used in algorithm)
	jacobsthal.push_back(1); // J(1) = 1

	int i = 2;
	while (jacobsthal.back() < n)
	{
		// J(n) = J(n-1) + 2*J(n-2)
		int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
		jacobsthal.push_back(next);
		i++;
	}

	return (jacobsthal);
}

// Generate insertion sequence based on Jacobsthal numbers
std::vector<int> PmergeMe::generateInsertionSequence(int n)
{
	// Get Jacobsthal numbers
	std::vector<int> jacobsthal = generateJacobsthalNumbers(n);

	// Create the insertion sequence
	std::vector<int> sequence;

	// Start with inserting element at index 1 (second element)
	sequence.push_back(1);

	// For each Jacobsthal number, add it and then add all elements between
	// it and the previous Jacobsthal number in reverse order
	for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] <= n; i++)
	{
		sequence.push_back(jacobsthal[i]);

		// Add elements between current and previous Jacobsthal number in reverse
		for (int j = jacobsthal[i] - 1; j > jacobsthal[i-1]; j--)
			if (j <= n)
				sequence.push_back(j);
	}

	// Add any remaining elements in reverse order
	for (int i = n; i > jacobsthal[jacobsthal.size()-1]; i--)
		sequence.push_back(i);
	return (sequence);
}
// Ford-Johnson sort with proper Jacobsthal sequence
void PmergeMe::ford_johnson_sort_vector(std::vector<int> &arr)
{
	if (arr.size() <= 1)
		return;

	// Step 1: Form pairs and find larger/smaller elements
	std::vector<ElementPair> pairs;
	bool has_odd_element = (arr.size() % 2 != 0);
	int odd_element = has_odd_element ? arr.back() : 0;

	for (size_t i = 0; i < (has_odd_element ? arr.size() - 1 : arr.size()); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	// Step 2: Sort the larger elements recursively
	recursive_sort(pairs, 0, pairs.size() - 1);

	// Step 3: Set up main chain and pending elements
	std::vector<int> main_chain;
	std::vector<int> pending;

	// Add all larger elements to main chain
	for (size_t i = 0; i < pairs.size(); ++i) {
		main_chain.push_back(pairs[i].first);
		pending.push_back(pairs[i].second);
	}

	// Step 4: Insert pending elements using Jacobsthal sequence
	if (!pending.empty())
	{
		// Insert first pending element (index 0)
		binary_insert(main_chain, pending[0]);

		// Generate insertion sequence for remaining elements
		std::vector<int> insertion_sequence = generateInsertionSequence(pending.size() - 1);

		// Insert remaining elements according to sequence
		for (size_t i = 0; i < insertion_sequence.size(); ++i)
			if (insertion_sequence[i] < (int)pending.size())
				binary_insert(main_chain, pending[insertion_sequence[i]]);
	}

	// Insert odd element if present
	if (has_odd_element)
		binary_insert(main_chain, odd_element);
	arr = main_chain;
}

// Deque implementation follows the same approach
void PmergeMe::ford_johnson_sort_deque(std::deque<int> &arr)
{
	if (arr.size() <= 1)
		return;

	// Step 1: Form pairs and find larger/smaller elements
	std::vector<ElementPair> pairs;
	bool has_odd_element = (arr.size() % 2 != 0);
	int odd_element = has_odd_element ? arr.back() : 0;

	for (size_t i = 0; i < (has_odd_element ? arr.size() - 1 : arr.size()); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}

	// Step 2: Sort the larger elements recursively
	recursive_sort(pairs, 0, pairs.size() - 1);

	// Step 3: Set up main chain and pending elements
	std::deque<int> main_chain;
	std::vector<int> pending;

	// Add all larger elements to main chain
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		main_chain.push_back(pairs[i].first);
		pending.push_back(pairs[i].second);
	}

	// Step 4: Insert pending elements using Jacobsthal sequence
	if (!pending.empty())
	{
		// Insert first pending element (index 0)
		binary_insert(main_chain, pending[0]);

		// Generate insertion sequence for remaining elements
		std::vector<int> insertion_sequence = generateInsertionSequence(pending.size() - 1);

		// Insert remaining elements according to sequence
		for (size_t i = 0; i < insertion_sequence.size(); ++i)
			if (insertion_sequence[i] < (int)pending.size())
				binary_insert(main_chain, pending[insertion_sequence[i]]);
	}

	// Insert odd element if present
	if (has_odd_element)
		binary_insert(main_chain, odd_element);
	arr = main_chain;
}

