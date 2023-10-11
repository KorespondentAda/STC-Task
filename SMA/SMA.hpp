#include <vector>

/// Calculate SMA value of #data points with #k samples size window to #sma
///
/// @param [in] k Window size, samples
/// @param [in] data Input data samples
/// @param [out] sma Output SMA samples
template<class T>
void SimpleMovingAverage(int k, const std::vector<T> &data, std::vector<T> &sma);

/// Calculate SMA value of #data points with #k samples size window
///
/// @param k Window size, samples
/// @param data Input data samples
/// @return Vector of calculated SMAs
template<class T>
std::vector<T> SimpleMovingAverage(int k, const std::vector<T> &data) {
	std::vector<T> result;
	SimpleMovingAverage(k, data, result);
	return result;
}

