cmake_minimum_required(VERSION 4.0)
project(cpp_sample)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_sample main.cpp
        counter.h
        counter.cpp
        overflow-bug.cpp)
