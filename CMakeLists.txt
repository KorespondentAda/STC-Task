cmake_minimum_required(VERSION 3.15)

project(STC-Task)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(SMA)

add_executable(sma-sample main.cpp)
target_link_libraries(sma-sample PUBLIC SMA)

add_executable(sma-measure timeMeasure.cpp)
target_link_libraries(sma-measure PUBLIC SMA)

enable_testing()

