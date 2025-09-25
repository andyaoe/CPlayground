#include <stdio.h>
#include <math.h>

// Quaternion structure: q = w + xi + yj + zk
typedef struct {
    float w, x, y, z;
} Quaternion;

// Create a quaternion from scalar and vector parts
Quaternion quat_create(float w, float x, float y, float z) {
    Quaternion q = {w, x, y, z};
    return q;
}

// Create identity quaternion (no rotation)
Quaternion quat_identity() {
    return quat_create(1.0f, 0.0f, 0.0f, 0.0f);
}

// Create quaternion from axis-angle representation
Quaternion quat_from_axis_angle(float x, float y, float z, float angle) {
    float half_angle = angle * 0.5f;
    float sin_half = sinf(half_angle);
    float cos_half = cosf(half_angle);
    
    // Normalize axis vector
    float length = sqrtf(x*x + y*y + z*z);
    if (length > 0.0f) {
        x /= length;
        y /= length;
        z /= length;
    }
    
    return quat_create(cos_half, x * sin_half, y * sin_half, z * sin_half);
}

// Quaternion addition
Quaternion quat_add(Quaternion a, Quaternion b) {
    return quat_create(a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z);
}

// Quaternion multiplication (Hamilton product)
Quaternion quat_multiply(Quaternion a, Quaternion b) {
    return quat_create(
        a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z,  // w
        a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y,  // x
        a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x,  // y
        a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w   // z
    );
}

// Quaternion conjugate (negate vector part)
Quaternion quat_conjugate(Quaternion q) {
    return quat_create(q.w, -q.x, -q.y, -q.z);
}

// Quaternion magnitude (norm)
float quat_magnitude(Quaternion q) {
    return sqrtf(q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z);
}

// Normalize quaternion to unit length
Quaternion quat_normalize(Quaternion q) {
    float mag = quat_magnitude(q);
    if (mag > 0.0f) {
        return quat_create(q.w/mag, q.x/mag, q.y/mag, q.z/mag);
    }
    return quat_identity();
}

// Quaternion inverse
Quaternion quat_inverse(Quaternion q) {
    float mag_sq = q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z;
    if (mag_sq > 0.0f) {
        Quaternion conj = quat_conjugate(q);
        return quat_create(conj.w/mag_sq, conj.x/mag_sq, conj.y/mag_sq, conj.z/mag_sq);
    }
    return quat_identity();
}

// Convert quaternion to 3x3 rotation matrix
void quat_to_matrix(Quaternion q, float matrix[3][3]) {
    // Normalize quaternion first
    q = quat_normalize(q);
    
    float xx = q.x * q.x;
    float yy = q.y * q.y;
    float zz = q.z * q.z;
    float xy = q.x * q.y;
    float xz = q.x * q.z;
    float yz = q.y * q.z;
    float wx = q.w * q.x;
    float wy = q.w * q.y;
    float wz = q.w * q.z;
    
    matrix[0][0] = 1.0f - 2.0f * (yy + zz);
    matrix[0][1] = 2.0f * (xy - wz);
    matrix[0][2] = 2.0f * (xz + wy);
    
    matrix[1][0] = 2.0f * (xy + wz);
    matrix[1][1] = 1.0f - 2.0f * (xx + zz);
    matrix[1][2] = 2.0f * (yz - wx);
    
    matrix[2][0] = 2.0f * (xz - wy);
    matrix[2][1] = 2.0f * (yz + wx);
    matrix[2][2] = 1.0f - 2.0f * (xx + yy);
}

// Rotate a 3D vector using a quaternion
void quat_rotate_vector(Quaternion q, float vec[3], float result[3]) {
    // Convert vector to quaternion (w=0)
    Quaternion v = quat_create(0.0f, vec[0], vec[1], vec[2]);
    
    // Rotation: q * v * q^(-1)
    Quaternion q_inv = quat_inverse(q);
    Quaternion temp = quat_multiply(q, v);
    Quaternion rotated = quat_multiply(temp, q_inv);
    
    result[0] = rotated.x;
    result[1] = rotated.y;
    result[2] = rotated.z;
}

// Spherical linear interpolation (SLERP) between two quaternions
Quaternion quat_slerp(Quaternion a, Quaternion b, float t) {
    // Normalize quaternions
    a = quat_normalize(a);
    b = quat_normalize(b);
    
    // Compute dot product
    float dot = a.w*b.w + a.x*b.x + a.y*b.y + a.z*b.z;
    
    // If dot product is negative, negate one quaternion to take shorter path
    if (dot < 0.0f) {
        b.w = -b.w; b.x = -b.x; b.y = -b.y; b.z = -b.z;
        dot = -dot;
    }
    
    // If quaternions are very similar, use linear interpolation
    if (dot > 0.9995f) {
        Quaternion result = quat_create(
            a.w + t * (b.w - a.w),
            a.x + t * (b.x - a.x),
            a.y + t * (b.y - a.y),
            a.z + t * (b.z - a.z)
        );
        return quat_normalize(result);
    }
    
    // Calculate angle and perform spherical interpolation
    float theta = acosf(dot);
    float sin_theta = sinf(theta);
    float factor_a = sinf((1.0f - t) * theta) / sin_theta;
    float factor_b = sinf(t * theta) / sin_theta;
    
    return quat_create(
        factor_a * a.w + factor_b * b.w,
        factor_a * a.x + factor_b * b.x,
        factor_a * a.y + factor_b * b.y,
        factor_a * a.z + factor_b * b.z
    );
}

// Print quaternion
void quat_print(Quaternion q) {
    printf("(%.3f, %.3f, %.3f, %.3f)\n", q.w, q.x, q.y, q.z);
}

// Example usage and demonstrations
int main() {
    printf("=== Quaternion Math Examples ===\n\n");
    
    // Example 1: Basic quaternion operations
    printf("1. Basic Operations:\n");
    Quaternion q1 = quat_create(1.0f, 2.0f, 3.0f, 4.0f);
    Quaternion q2 = quat_create(2.0f, 1.0f, 0.5f, 1.5f);
    
    printf("q1 = "); quat_print(q1);
    printf("q2 = "); quat_print(q2);
    
    Quaternion sum = quat_add(q1, q2);
    printf("q1 + q2 = "); quat_print(sum);
    
    Quaternion product = quat_multiply(q1, q2);
    printf("q1 * q2 = "); quat_print(product);
    
    printf("Magnitude of q1: %.3f\n", quat_magnitude(q1));
    
    Quaternion q1_normalized = quat_normalize(q1);
    printf("Normalized q1 = "); quat_print(q1_normalized);
    printf("\n");
    
    // Example 2: Rotation using quaternions
    printf("2. Rotation Example:\n");
    // Create rotation of 90 degrees around Y-axis
    float angle = M_PI / 2.0f;  // 90 degrees in radians
    Quaternion rotation = quat_from_axis_angle(0.0f, 1.0f, 0.0f, angle);
    printf("90° rotation around Y-axis: "); quat_print(rotation);
    
    // Rotate a vector (1, 0, 0) - should become (0, 0, -1)
    float vector[3] = {1.0f, 0.0f, 0.0f};
    float rotated_vector[3];
    quat_rotate_vector(rotation, vector, rotated_vector);
    printf("Vector (1, 0, 0) rotated: (%.3f, %.3f, %.3f)\n", 
           rotated_vector[0], rotated_vector[1], rotated_vector[2]);
    
    // Convert to rotation matrix
    float matrix[3][3];
    quat_to_matrix(rotation, matrix);
    printf("Rotation matrix:\n");
    for (int i = 0; i < 3; i++) {
        printf("  [%.3f, %.3f, %.3f]\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
    printf("\n");
    
    // Example 3: Quaternion interpolation (SLERP)
    printf("3. Spherical Linear Interpolation (SLERP):\n");
    Quaternion start_rot = quat_identity();  // No rotation
    Quaternion end_rot = quat_from_axis_angle(0.0f, 0.0f, 1.0f, M_PI);  // 180° around Z
    
    printf("Start rotation: "); quat_print(start_rot);
    printf("End rotation: "); quat_print(end_rot);
    
    // Interpolate at different points
    for (float t = 0.0f; t <= 1.0f; t += 0.25f) {
        Quaternion interpolated = quat_slerp(start_rot, end_rot, t);
        printf("t = %.2f: ", t); quat_print(interpolated);
    }
    printf("\n");
    
    // Example 4: Combining rotations
    printf("4. Combining Rotations:\n");
    Quaternion rot_x = quat_from_axis_angle(1.0f, 0.0f, 0.0f, M_PI/4);  // 45° around X
    Quaternion rot_y = quat_from_axis_angle(0.0f, 1.0f, 0.0f, M_PI/6);  // 30° around Y
    
    printf("45° rotation around X: "); quat_print(rot_x);
    printf("30° rotation around Y: "); quat_print(rot_y);
    
    // Combined rotation: first X, then Y
    Quaternion combined = quat_multiply(rot_y, rot_x);
    printf("Combined rotation (Y then X): "); quat_print(combined);
    
    return 0;
}