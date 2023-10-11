#include <vector>

template<class T>
void SimpleMovingAverage(int k, const std::vector<T> &data, std::vector<T> &sma) {
	int smaSize = data.size() - (k - 1);
	sma.resize(smaSize);

	/// First SMA value is just average of #data first #k elements
	sma[0] = 0;
	for (int i = 0; i < k; i++) {
		sma[0] += data[i];
	}
	sma[0] /= k;

	/// Every next value calculated iteratively
	for (int i = 0; i < smaSize-1; i++) {
		int idxPrev = i;
		int idxNext = i + k;
		sma[i + 1] = sma[i] + ((data[idxNext] - data[idxPrev]) / k);
	}
}

template void SimpleMovingAverage<float>(int k, const std::vector<float> &data, std::vector<float> &sma);
template void SimpleMovingAverage<double>(int k, const std::vector<double> &data, std::vector<double> &sma);

