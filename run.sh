#!/bin/bash

# Run script for Quaternion Math project
# This script builds the project (if needed) and runs the executable

set -e  # Exit on any error

echo "=== Quaternion Math Run Script ==="
echo ""

# Check if executable exists, if not build it
if [ ! -f "build/bin/quaternion_math" ]; then
    echo "Executable not found. Building project first..."
    echo ""
    ./build.sh
    echo ""
fi

echo "Running Quaternion Math program..."
echo "=========================================="
echo ""

# Run the executable
./build/bin/quaternion_math

echo ""
echo "=========================================="
echo "Program execution completed."
