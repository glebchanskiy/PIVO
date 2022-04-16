cmake_minimum_required(VERSION 3.21)
project(new_shortest)

set(CMAKE_CXX_STANDARD 14)

add_executable(new_shortest main.cpp Graph.cpp Graph.h tester.h)
