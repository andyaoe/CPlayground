cmake_minimum_required(VERSION 3.10)

# Project name and version
project(QuaternionMath VERSION 1.0.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")

# Add math library for linking
find_library(MATH_LIBRARY m)

# Create the executable
add_executable(quaternion_math main.c)

# Link with math library
target_link_libraries(quaternion_math ${MATH_LIBRARY})

# Set output directory
set_target_properties(quaternion_math PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Print build information
message(STATUS "Building Quaternion Math Library")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")

# Optional: Add install target
install(TARGETS quaternion_math
    RUNTIME DESTINATION bin
)
