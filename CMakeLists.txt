cmake_minimum_required(VERSION 3.12)
# ---------------------------------------------------------------------------------------
# Set default build to release
# ---------------------------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

message(STATUS "CMAKE_BUILD_TYPE:${CMAKE_BUILD_TYPE}")
# ---------------------------------------------------------------------------------------
# Compiler config
# ---------------------------------------------------------------------------------------
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()
message(STATUS "CMAKE_CXX_STANDARD:${CMAKE_CXX_STANDARD}")

project(cstudy VERSION 1.0.0 LANGUAGES C CXX)
add_subdirectory(src/c)
add_subdirectory(src/catch)
add_subdirectory(src/test)