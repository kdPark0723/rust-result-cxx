cmake_minimum_required(VERSION 3.15)
project(rust_result)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_library(rust_result include/result.h)