#include <iostream>
#include <vector>
#include "SMA.hpp"

using SAMPLE_T = float;

/// SimpleMovingAverage() usage example
int main() {
	/// Read number of data points #n and window size #k, in samples
	int n, k;
	std::cin >> n >> k;

	if (std::cin.eof()) {
		std::cerr << "Wrong input! Must be `<n> <k> [<s>...]`" << std::endl;
		std::cerr << "Here <n> is sample count, <k> is window size, <s> is actual samples" << std::endl;
		return 1;
	}

	if (n < k) {
		std::cerr << "Wrong input! Window size can't be larger than data!" << std::endl;
		return 1;
	}

	if (n <= 0) {
		std::cerr << "Wrong input! Sample count can't be less than 1!" << std::endl;
		return 1;
	}

	if (k <= 0) {
		std::cerr << "Wrong input! Window size can't be less than 1!" << std::endl;
		return 1;
	}


	std::vector<SAMPLE_T> data(n, 0);

	/// Then read #n samples from stdin
	for (int i = 0; i < n; i++) {
		std::cin >> data[i];
	}

	std::vector<SAMPLE_T> sma = SimpleMovingAverage(k, data);

	/// Write calculated SMAs to stdout
	for (auto sample : sma) {
		std::cout << sample << std::endl;
	}

	return 0;
}

