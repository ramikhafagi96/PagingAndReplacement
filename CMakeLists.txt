cmake_minimum_required(VERSION 3.12)
project(PageReplacement)

set(CMAKE_CXX_STANDARD 14)

add_executable(PageReplacement main.cpp ReplacementPolicies/LRU_Int.h ImportantIncludes.h ReplacementPolicies/LRU_Prog.cpp main.cpp ReplacementPolicies/FIFO_Int.h ReplacementPolicies/FIFO_Prog.cpp ReplacementPolicies/CLOCK_Int.h ReplacementPolicies/CLOCK_Prog.cpp)