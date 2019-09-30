cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode
    problem1/sumOfTwoNumbers.cpp
    problem2/addTwoNumbers.cpp
    problem3/lengthOfLongestSubstring.cpp
    problem4/findMedianSortedArrays.cpp
    problem5/longestPalindrome.cpp
    problem6/convert.cpp
    problem7/reverse.cpp
    problem8/atoi.cpp
    problem9/isPalindrome.cpp
    problem10/match.cpp
    problem11/maxArea.cpp
    problem12/intToRoman.cpp
    problem13/romanToInt.cpp
    problem14/longestCommonPrefix.cpp
    problem15/threeSum.cpp
    problem16/threeSumClosest.cpp problem17/letterCombinations.cpp)
