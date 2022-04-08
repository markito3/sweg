# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.0)

file(GLOB SRCS "*.text") # make a list of the input files
message(STATUS "SRCS = ${SRCS}")
set(OUTFILES) # set the list of output files to blank
foreach(SRC ${SRCS}) # for each input file, create a custom command
  message(STATUS "SRC = ${SRC}")
  set(OUTPUT_FILE_NAME_1 ${SRC}.made1)
  set(OUTPUT_FILE_NAME_2 ${SRC}.made2)
  message(STATUS "OUTPUT_FILE_NAME_1 = ${OUTPUT_FILE_NAME_1}")
  message(STATUS "OUTPUT_FILE_NAME_2 = ${OUTPUT_FILE_NAME_2}")
  add_custom_command( # make a command that does the copy
    OUTPUT ${OUTPUT_FILE_NAME_1} ${OUTPUT_FILE_NAME_2}
    COMMAND cp -v ${SRC} ${OUTPUT_FILE_NAME_1}
    COMMAND cp -v ${SRC} ${OUTPUT_FILE_NAME_2}
    DEPENDS ${SRC}
    )
  set(OUTFILES ${OUTFILES} ${OUTPUT_FILE_NAME_1} ${OUTPUT_FILE_NAME_2}) # add the output file to the
  # list of output files
endforeach(SRC)
add_custom_target(target_all # the name of the target is a .PHONY make target
  ALL # make target the default target
  DEPENDS ${OUTFILES} # have the target depend on all of the output files.
  )
