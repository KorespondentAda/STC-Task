add_library(SMA SMA.cpp)
target_include_directories(SMA INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

option(USE_FLOAT "Use float instead of double as samples type" OFF)

if(USE_FLOAT)
	target_compile_definitions(SMA PUBLIC SAMPLE_T=float)
else()
	target_compile_definitions(SMA PUBLIC SAMPLE_T=double)
endif()

