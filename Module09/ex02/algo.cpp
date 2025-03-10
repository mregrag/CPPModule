#include <iostream>
#include <vector>
#include <algorithm>

struct s_pair {
	int high;
	int low;
};

void binary_insert(std::vector<int> &arr, int value) {
	auto pos = std::lower_bound(arr.begin(), arr.end(), value);
	arr.insert(pos, value);
}

void recursive_sort(std::vector<s_pair> &pairs, int left, int right) {
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	recursive_sort(pairs, left, mid);
	recursive_sort(pairs, mid + 1, right);

	std::vector<s_pair> temp;
	int i = left, j = mid + 1;

	while (i <= mid && j <= right) {
		if (pairs[i].high <= pairs[j].high)
			temp.push_back(pairs[i++]);
		else
			temp.push_back(pairs[j++]);
	}

	while (i <= mid)
		temp.push_back(pairs[i++]);
	while (j <= right)
		temp.push_back(pairs[j++]);

	std::copy(temp.begin(), temp.end(), pairs.begin() + left);
}

void ford_johnson_sort(std::vector<int> &arr) {
	int n = arr.size();
	if (n <= 1)
		return;

	std::vector<s_pair> pairs;
	for (size_t i = 0; i + 1 < arr.size(); i += 2) {
		if (arr[i] < arr[i + 1])
			pairs.push_back({arr[i + 1], arr[i]});
		else
			pairs.push_back({arr[i], arr[i + 1]});
	}

	recursive_sort(pairs, 0, pairs.size() - 1);

	std::vector<int> sorted;
	sorted.push_back(pairs[0].high);
	for (const auto &p : pairs) {
		sorted.push_back(p.high);
		binary_insert(sorted, p.low);
	}

	if (n % 2 != 0)
		binary_insert(sorted, arr.back());

	arr = sorted;
}

int main() {
	std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
	ford_johnson_sort(arr);

	std::cout << "Sorted array: ";
	for (int num : arr)
		std::cout << num << " ";
	std::cout << std::endl;

	return 0;
}

