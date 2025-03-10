/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fordjhnson.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:08:55 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/04 02:54:40 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Ford-Johnson algorithm (Merge-Insertion Sort)
void fordJohnsonSort(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return;

	// Step 1: Form pairs and find the larger element of each pair
	std::vector<std::pair<int, int>> pairs;
	std::vector<int> leftover;

	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		if (arr[i] < arr[i + 1])
			pairs.push_back({arr[i + 1], arr[i]});
		else
			pairs.push_back({arr[i], arr[i + 1]});
	}

	// Handle odd-sized arrays
	if (arr.size() % 2 == 1)
		leftover.push_back(arr.back());

	// Step 2: Extract the larger elements for recursive sorting
	std::vector<int> largerElements;
	for (const auto& pair : pairs)
		largerElements.push_back(pair.first);

	// Step 3: Recursively sort the larger elements
	fordJohnsonSort(largerElements);

	// Step 4: Recreate the array with the sorted larger elements
	arr.clear();
	for (int val : largerElements)
		arr.push_back(val);

	// Step 5: Insert the smaller elements using binary insertion
	// following the Jacobsthal numbers ordering
	std::vector<int> smallerElements;
	for (const auto& pair : pairs)
		smallerElements.push_back(pair.second);

	// Calculate Jacobsthal numbers (or use a predefined sequence)
	std::vector<int> jacobsthalIndices;
	std::vector<bool> inserted(smallerElements.size(), false);

	// Jacobsthal numbers: 1, 3, 5, 11, 21, 43, ...
	int a = 1, b = 3;
	while (a <= smallerElements.size())
	{
		int idx = a - 1;
		if (idx < smallerElements.size() && !inserted[idx])
		{
			jacobsthalIndices.push_back(idx);
			inserted[idx] = true;
		}

		int next = 2 * b - a;
		a = b;
		b = next;
	}

	// Fill in remaining indices in descending order of ranges
	for (int len = smallerElements.size(); len > 0; len--)
	{
		for (int i = len - 1; i >= 0; i--)
		{
			if (!inserted[i])
			{
				jacobsthalIndices.push_back(i);
				inserted[i] = true;
			}
		}
	}

	// Binary insert smaller elements in Jacobsthal order
	for (int idx : jacobsthalIndices)
	{
		int val = smallerElements[idx];
		auto it = std::lower_bound(arr.begin(), arr.end(), val);
		arr.insert(it, val);
	}

	// Add the leftover element from odd-sized array
	if (!leftover.empty())
	{
		auto it = std::lower_bound(arr.begin(), arr.end(), leftover[0]);
		arr.insert(it, leftover[0]);
	}
}

// Utility function to print the array
void printArray(const std::vector<int>& arr)
{
	for (int num : arr)
		std::cout << num << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> arr = {3, 5, 9, 7, 4};
	std::cout << "Original array: ";
	printArray(arr);

	fordJohnsonSort(arr);

	std::cout << "Sorted array: ";
	printArray(arr);
	return 0;
}
