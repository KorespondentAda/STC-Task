#include <vector>

/// @def SAMPLE_T Type of data. Defined by CMake. Can be `float` or `double`

/// Calculate SMA value of #data points with #k point size window
///
/// @param k Window size, samples
/// @param data Input data samples
/// @return Vector of calculated SMAs
std::vector<SAMPLE_T> SimpleMovingAverage(int k, std::vector<SAMPLE_T> data);

