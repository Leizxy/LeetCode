cmake_minimum_required(VERSION 3.17)
project(LeetCode C)

add_subdirectory(q1-50)
#add_subdirectory(q51-100)
set(CMAKE_C_STANDARD 99)

#target_include_directories(/support/*)

add_executable(main1 main.c)


add_executable(456 leet456.c)
add_executable(1006 leet1006.c)