# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.0)

# Project's name

project(custom)
add_custom_command( # make a command that does the copy
  OUTPUT ../a.txt.made
  COMMAND cp -v ../a.txt ../a.txt.made  
  DEPENDS ../a.txt
  )
add_custom_target(target_a # the name of the target is a .PHONY make target
  ALL # make target_a the default target
  DEPENDS ../a.txt.made # have the target depend on an output file. it will
  # use the custom command to generate the file
  )
