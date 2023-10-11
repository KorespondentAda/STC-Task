cmake_minimum_required(VERSION 3.15)

project(STC-Task)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(SMA)

add_executable(sma-sample main.cpp)
target_link_libraries(sma-sample PUBLIC SMA)

add_executable(sma-test test.cpp)
target_link_libraries(sma-test PUBLIC SMA)

