# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.0)

# Project's name

project(custom)
file(GLOB SRCS "*.txt") # make a list of the input files
message(STATUS "SRCS = ${SRCS}")
set(OUTFILES) # set the list of output files to blank
foreach(SRC ${SRCS}) # for each input file, create a custom command
  message(STATUS "SRC = ${SRC}")
  set(OUTPUT_FILE_NAME ${SRC}.made)
  message(STATUS "OUTPUT_FILE_NAME = ${OUTPUT_FILE_NAME}")
  add_custom_command( # make a command that does the copy
    OUTPUT ${OUTPUT_FILE_NAME}
    COMMAND cp -v ${SRC} ${OUTPUT_FILE_NAME}
    DEPENDS ${SRC}
    )
  set(OUTFILES ${OUTFILES} ${OUTPUT_FILE_NAME}) # add the output file to the
  # list of output files
endforeach(SRC)
add_custom_target(target_a # the name of the target is a .PHONY make target
  ALL # make target_a the default target
  DEPENDS ${OUTFILES} # have the target depend on all of the output files.
  )