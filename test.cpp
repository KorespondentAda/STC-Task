#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "SMA.hpp"

template<class T>
void Test(int k, int count, double freq) {
	std::vector<T> data(count);
	std::random_device d;
	std::default_random_engine re(d());
	std::uniform_real_distribution<T> rd(-10, 10);

	std::ofstream out("test.csv");

	/// Generate data samples
	for (int i = 0; i < count; i++) {
		data[i] = rd(re) + 20*std::sin(6.28 * i * freq);
	}

	/// Calculate SMA samples
	auto sma = SimpleMovingAverage(k, data);

	/// Write samples down
	out << "Input,Output" << std::endl;
	for (int i = 0; i < k-1; i++) {
		out << data[i]
			<< ',' << '0'
			<< std::endl;
	}
	for (int i = 0; i < sma.size(); i++) {
		out << data[i+k-1]
			<< ',' << sma[i]
			<< std::endl;
	}

	out.close();
}

/// Simple tester for SimpleMovingAverage()
///
/// Generate input and output data for further correctness checks
/// Generated input and output will be written to "test.csv" in two columns
/// For test control 4 arguments must be used:
/// - type: 0 for float, other for double
/// - k: window size, samples
/// - count: data samples count
/// - freq: frequency of generated input harmonic signal
int main(int argc, char *argv[]) {
	if (argc < 4) {
		return 1;
	}

	int type = std::stoi(argv[1]);
	int k = std::stoi(argv[2]);
	int count = std::stoi(argv[3]);
	double freq = std::stod(argv[4]);

	if (type == 0) {
		Test<float>(k, count, freq);
	} else {
		Test<double>(k, count, freq);
	}

	return 0;
}

