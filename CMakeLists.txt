cmake_minimum_required(VERSION 3.15)
project(AlgorithmicToolbox)

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -O2")

add_executable(main main.cpp)
add_executable(stress_test stress_test.cpp)
add_executable(aplusb aplusb.cpp)
