#include <vector>

std::vector<SAMPLE_T> SimpleMovingAverage(int k, std::vector<SAMPLE_T> data) {
	int smaSize = data.size() - (k - 1);
	std::vector<SAMPLE_T> sma(smaSize);

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

	return sma;
}

