# CMake version required to build
cmake_minimum_required(VERSION 3.28)

# Project name
project(standalones DESCRIPTION "Standalones Project" LANGUAGES CXX)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Specify the output directories for built files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)