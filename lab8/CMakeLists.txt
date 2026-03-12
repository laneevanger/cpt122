cmake_minimum_required(VERSION 3.10)
project(LAB8)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(lab8task1)

add_executable(LAB8 bin/main.cpp)