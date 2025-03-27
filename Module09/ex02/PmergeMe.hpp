/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:42:06 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/22 21:46:07 by mregrag          ###   ########.fr       */
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
#include <climits>

class PmergeMe
{
	private:

		std::vector<int> _vector;
		std::deque<int> _deque;

		void parse_input(int argc, char **argv);
		void print_sequence(const std::vector<int> &seq);
		std::string trim(const std::string& s);

		void binary_insert(std::vector<int> &arr, int value);
		void binary_insert(std::deque<int> &arr, int value);


		void sortVector();
		void sortDeque();

		std::vector<size_t> generateInsertionOrder(size_t m);

	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sortAndDisplay();
};

#endif
