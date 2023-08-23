cmake_minimum_required(VERSION 3.23)
project(mySheets)

set(CMAKE_C_STANDARD 20)



add_executable(mySheets
        common.h main.cpp structures.cpp test_runner_p.h)
