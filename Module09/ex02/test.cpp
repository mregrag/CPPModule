/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:48:18 by mregrag           #+#    #+#             */
/*   Updated: 2025/03/03 20:54:14 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

// Merge two sorted subarrays into one sorted array
void merge(std::vector<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1; // Size of left subarray
	int n2 = right - mid;    // Size of right subarray

	// Create temporary arrays for left and right subarrays
	std::vector<int> L(n1), R(n2);

	// Copy data to temporary arrays
	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	// Merge the temporary arrays back into arr[left..right]
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
		k++;
	}

	// Copy remaining elements of L[] if any
	while (i < n1)
		arr[k++] = L[i++];

	// Copy remaining elements of R[] if any
	while (j < n2)
		arr[k++] = R[j++];
}

// Recursive merge sort function
void mergeSort(std::vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2; // Avoid overflow
		std::cout << "mid : " << mid << std::endl;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right); // Sort right half
		std::cout << "yes" << std::endl;
		merge(arr, left, mid, right); // Merge sorted halves
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

	mergeSort(arr, 0, arr.size() - 1);

	std::cout << "Sorted array: ";
	printArray(arr);

	return 0;
}
