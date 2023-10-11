#include <vector>

/// Calculate SMA value of #data points with #k point size window
///
/// @param k Window size, samples
/// @param data Input data samples
/// @return Vector of calculated SMAs
template<class T>
std::vector<T> SimpleMovingAverage(int k, std::vector<T> data);

