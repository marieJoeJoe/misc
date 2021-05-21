cmake_minimum_required (VERSION 3.5)

project(cxxclass)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_file "${source_dir}/*.cpp")

add_executable(cxxclass ${source_file})