#include <chrono>
#include <fstream>
#include <random>
#include <vector>
#include "SMA.hpp"

template<class T>
double Test(int k, int count) {
	std::vector<T> data(count);
	std::random_device d;
	std::default_random_engine re(d());
	std::uniform_real_distribution<T> rd(-10, 10);

	for (int i = 0; i < count; i++) {
		data[i] = rd(re);
	}

	const auto start {std::chrono::steady_clock::now()};
	volatile auto res = SimpleMovingAverage(k, data);
	const auto end {std::chrono::steady_clock::now()};

	const std::chrono::duration<double> dur(end - start);
	return dur.count();
}

int main() {
	// Input data length
	int length = 1000000;
	// Will be tested for list of window sizes:
	int winSizes[] = {4, 8, 16, 32, 64, 128};

	std::ofstream out("measure.csv");

	out << "WinSize,Float,Double" << std::endl;
	for (auto ws : winSizes) {
		out << ws
			<< ',' << length / Test<float>(ws, length)
			<< ',' << length / Test<double>(ws, length)
			<< std::endl;
	}

	out.close();

	return 0;
}
