# CMake version required to build
cmake_minimum_required(VERSION 3.10)

# Project name
project(standalones DESCRIPTION "Standalones Project" LANGUAGES CXX)

# Specify the output directories for built files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)