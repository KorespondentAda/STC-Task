cmake_minimum_required(VERSION 3.15)

project(STC-Task)

add_subdirectory(SMA)

add_executable(sma-sample main.cpp)
target_link_libraries(sma-sample PUBLIC SMA)

enable_testing()

