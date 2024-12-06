cmake_minimum_required(VERSION 3.20)
# Project name
project(TempMonitoring_Project)

set(CMAKE_CXX_COMPILER clang++)

# Set the C++ standard to C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags for C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -I${CMAKE_SOURCE_DIR}/include")

# Collect all source files in the src directory
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})