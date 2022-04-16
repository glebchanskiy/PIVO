cmake_minimum_required(VERSION 3.21)
project(parse_set)

set(CMAKE_CXX_STANDARD 14)

add_executable(parse_set main.cpp Set.cpp Set.h parser.cpp parser.h)
