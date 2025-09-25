#!/bin/bash

# Build script for Quaternion Math project
# This script creates a build directory, configures CMake, and builds the project

set -e  # Exit on any error

echo "=== Quaternion Math Build Script ==="
echo ""

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

# Change to build directory
cd build

echo "Configuring CMake..."
cmake .. -DCMAKE_BUILD_TYPE=Release

echo ""
echo "Building project..."
make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)

echo ""
echo "Build completed successfully!"
echo "Executable location: build/bin/quaternion_math"
echo ""
echo "To run the program:"
echo "  ./build/bin/quaternion_math"
echo "  or use: ./run.sh"
