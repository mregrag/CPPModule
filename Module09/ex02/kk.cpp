/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kk.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:33:28 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/10 03:40:00 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm> // for std::lower_bound

void binary_insert(std::vector<int> &arr, int value)
{
	std::vector<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), value);
	std::cout << "pos " << *pos << std::endl;
	arr.insert(pos, value);
}

int binary_search(int arr[], int size, int target)
{
	int low = 0, high = size - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;  // Avoids overflow

		if (arr[mid] == target)
			return mid;  // Found target
		else if (arr[mid] < target)
			low = mid + 1;  // Search right half
		else
			high = mid - 1; // Search left half
	}

	return -1;  // Target not found
}

int main(void)
{
	std::vector<int> vec = {2, 4};

	binary_insert(vec, 5);
	int arr[] = {1, 3, 5, 7, 9, 11};
	int size = sizeof(arr) / sizeof(arr[0]);
	int target = 4;


	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	int result = binary_search(arr, size - 1, target);
	if (result != -1)
		std::cout << "Element found at index " << result << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	return (0);
}
