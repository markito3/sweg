# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.0)

# Project's name

project(custom)
# use add_custom_target
add_custom_target(target_a # the name of the target is a .PHONY make target
  ALL # make target_a the default target
  COMMAND cp -v $(CMAKE_SOURCE_DIR)/a.txt $(CMAKE_SOURCE_DIR)/a.txt.made
  # here there is no dependence of a.txt.made on a.txt that cmake knows about
  # so the copy will be done every time
  )
