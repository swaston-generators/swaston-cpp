cmake_minimum_required (VERSION 3.0)
project (swaston-cpp)

set(CMAKE_CXX_STANDARD 98)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE MinSizeRel)
endif()

add_executable(swaston-cpp main.cpp)
target_include_directories(swaston-cpp PRIVATE ./include/)