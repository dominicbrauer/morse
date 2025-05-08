cmake_minimum_required(VERSION 3.10)
project(morse)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Include header files
include_directories(include)

# Gather source files
file(GLOB SOURCES "src/*.c")

# Create executable
add_executable(morse_built ${SOURCES})
