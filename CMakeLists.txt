cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode
    problem1/sumOfTwoNumbers.cpp
    problem2/addTwoNumbers.cpp
    problem3/lengthOfLongestSubstring.cpp
    problem4/findMedianSortedArrays.cpp)
