# Quaternion Math Library

A C implementation of quaternion mathematics with comprehensive rotation operations, interpolation, and matrix conversions.

## Features

- Basic quaternion operations (addition, multiplication, normalization)
- Axis-angle to quaternion conversion
- Quaternion to rotation matrix conversion
- Vector rotation using quaternions
- Spherical linear interpolation (SLERP)
- Rotation composition and combination

## Building and Running

### Prerequisites

- CMake 3.10 or higher
- C compiler with C99 support
- Make utility

### Quick Start

1. **Build the project:**
   ```bash
   ./build.sh
   ```

2. **Run the program:**
   ```bash
   ./run.sh
   ```

### Manual Build Steps

If you prefer to build manually:

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build the project
make -j$(nproc)

# Run the executable
./bin/quaternion_math
```

### Build Options

You can customize the build with CMake options:

```bash
# Debug build
cmake .. -DCMAKE_BUILD_TYPE=Debug

# Custom install prefix
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local

# Custom compiler
cmake .. -DCMAKE_C_COMPILER=gcc
```

## Project Structure

```
CPlayground/
├── main.c              # Main source file with quaternion implementation
├── CMakeLists.txt      # CMake configuration
├── build.sh            # Build script
├── run.sh              # Run script
├── README.md           # This file
└── build/              # Build directory (created by build.sh)
    └── bin/
        └── quaternion_math  # Compiled executable
```

## Examples

The program demonstrates:

1. **Basic Operations**: Quaternion addition, multiplication, normalization
2. **Rotation**: 90° rotation around Y-axis with vector transformation
3. **SLERP**: Spherical interpolation between rotations
4. **Combining Rotations**: Composition of multiple rotations

## Mathematical Background

This implementation follows the Hamilton quaternion convention:
- q = w + xi + yj + zk
- i² = j² = k² = ijk = -1
- ij = k, jk = i, ki = j

The library provides functions for:
- Creating quaternions from axis-angle representation
- Converting to/from rotation matrices
- Rotating 3D vectors
- Smooth interpolation between rotations

## License

This project is open source and available under the MIT License.
