cmake_minimum_required(VERSION 3.20)

# Project name
project(TempMonitoring_Project)

# Set the C compiler
set(CMAKE_C_COMPILER clang)

# Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g -I${CMAKE_SOURCE_DIR}/include")

# Collect all source files in the src directory
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})