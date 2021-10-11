# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.0)

# Project's name

project(custom)
add_custom_target(target_a
  ALL
  COMMAND cp -v $(CMAKE_SOURCE_DIR)/a.txt $(CMAKE_SOURCE_DIR)/a.txt.made
  )
