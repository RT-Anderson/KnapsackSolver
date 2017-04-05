cmake_minimum_required(VERSION 3.7)
project(knapsack)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/SolutionState.cpp src/SolutionState.h src/KnapsackItem.h src/Knapsack.h src/Knapsack.cpp)
add_executable(knapsack ${SOURCE_FILES})