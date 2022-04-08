# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.0)

# Project's name

project(main)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.c)
