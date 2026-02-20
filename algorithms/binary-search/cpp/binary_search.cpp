#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int binarySearch(const std::vector<int>& collection, int target) {
	int left = 0;
	int right = collection.size() -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (collection[mid] == target) return mid;
		if (collection[mid] > target) right = mid -1;
		if (collection[mid] < target) left = mid + 1;
	}

	return -1;
}

int main() {
	int size = 10'000'000;
	std::vector<int> collection(size);

	std::mt19937 rng(42);
	std::uniform_int_distribution<int> dist(1, 10);

	collection[0] = dist(rng);

	for (int i = 1; i < size; i++) {
		collection[i] = collection[i - 1] + dist(rng);
	}

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i< 1000; i++) {
		int target = collection[rng() % size];
		binarySearch(collection, target);
	}

	auto end = std::chrono::high_resolution_clock::now();

	auto ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	std::cout << "1000 search time: " << ms << " ms" << std::endl;

	return 0;
}

