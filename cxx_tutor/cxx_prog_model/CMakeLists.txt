cmake_minimum_required (VERSION 3.5)

project(Helloworld)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_file "${source_dir}/*.cpp")

add_executable(Helloworld ${source_file})