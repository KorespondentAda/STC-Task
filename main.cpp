#include <iostream>
#include <vector>
#include "SMA.hpp"

using SAMPLE_T = float;

int main() {
	/// Read number of data points #n and window size #k, in samples
	int n, k;
	std::cin >> n >> k;
	std::vector<SAMPLE_T> data(n);

	/// Then read #n samples from stdin
	for (int i = 0; i < n; i++) {
		std::cin >> data[i];
	}

	std::vector<SAMPLE_T> sma = SimpleMovingAverage(k, data);

	/// Write calculated SMAs to stdout
	for (int i = 0; i < sma.size(); i++) {
		std::cout << sma[i] << std::endl;
	}

	return 0;
}

