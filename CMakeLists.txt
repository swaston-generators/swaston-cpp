cmake_minimum_required (VERSION 3.0)
project (swaston-cpp)

set(CMAKE_CXX_STANDARD 98)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE MinSizeRel)
endif()

file(GLOB SOURCES
        ./*.cpp
        )

add_executable(swaston-cpp ${SOURCES})
target_include_directories(swaston-cpp PRIVATE ./include/)