#include <vector>

/// @def SAMPLE_T Type of data. Defined by CMake. Can be `float` or `double`

/// Calculate next SMA value by previous
/// Can be used directly for continuous processing
/// @return New SMA value
SAMPLE_T SimpleMovingAverageNext(int k, SAMPLE_T previous);

/// Calculate SMA value of #data points with #k point size window
/// @return Output data vector
std::vector<SAMPLE_T> SimpleMovingAverage(int k, std::vector<SAMPLE_T> data);

