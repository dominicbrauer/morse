cmake_minimum_required(VERSION 3.10)
project(morse)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Include header files
include_directories(include)

# Gather source files
file(GLOB SOURCES "src/*.c")

# Create executable
# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_executable(morse ${SOURCES})

# Find Doxygen
find_package(Doxygen REQUIRED)

if(DOXYGEN_FOUND)
    # Set the path to the Doxyfile if it's not in the root directory
    set(DOXYGEN_INPUT_DIR ${CMAKE_SOURCE_DIR}/src)
    set(DOXYGEN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/docs)

    # Add a target to generate documentation
    add_custom_target(
        doc_doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating Doxygen documentation"
        VERBATIM
    )
    
    # Make documentation a dependency of your main executable target
    add_dependencies(${PROJECT_NAME} doc_doxygen)
endif()
