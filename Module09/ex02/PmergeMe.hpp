/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:42:06 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/10 20:43:35 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <sstream>
# include <ctime>
# include <algorithm>
# include <stdexcept>
# include <utility>
#include <climits>

class PmergeMe
{
	private:
		typedef std::pair<int, int> ElementPair;

		std::vector<int> original;
		std::vector<int> _vector;
		std::deque<int> _deque;

		// Helper methods
		void parse_input(int argc, char **argv);
		void print_sequence(const std::vector<int> &seq);
		std::string trim(const std::string& s);

		// Binary insertion helpers
		void binary_insert(std::vector<int> &arr, int value);
		void binary_insert(std::deque<int> &arr, int value);

		// Merge sort helpers
		void recursive_sort(std::vector<ElementPair> &pairs, int left, int right);
		void merge_pairs(std::vector<ElementPair> &pairs, int left, int mid, int right);

		// Ford-Johnson sort implementations
		void ford_johnson_sort_vector(std::vector<int> &arr);
		void ford_johnson_sort_deque(std::deque<int> &arr);

		std::vector<int> generateJacobsthalNumbers(int n);
		std::vector<int> generateInsertionSequence(int n);

	public:
		// Orthodox Canonical Form
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		// Public method to perform sorting and display results
		void sort_and_display();
};

#endif
