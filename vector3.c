#include "vector3.h"
#include "matrix3.h"
#include <math.h>

struct vector3 vector3_zero = (struct vector3) {0, 0, 0};

struct vector3 vector3_new(double x, double y, double z)
{
    return (struct vector3) {x, y, z};
}

struct vector3 vector3_add(struct vector3 vector3, struct vector3 other_vector3)
{
    return vector3_new(vector3.x + other_vector3.x, vector3.y + other_vector3.y, vector3.z + other_vector3.z);
}

struct vector3 vector3_subtract(struct vector3 vector3, struct vector3 other_vector3)
{
    return vector3_new(vector3.x - other_vector3.x, vector3.y - other_vector3.y, vector3.z - other_vector3.z);
}

struct vector3 vector3_multiply(struct vector3 vector3, struct vector3 other_vector3)
{
    return vector3_new(vector3.x * other_vector3.x, vector3.y * other_vector3.y, vector3.z * other_vector3.z);
}

struct vector3 vector3_multiply_by_scalar(struct vector3 vector3, double scalar)
{
    return vector3_new(vector3.x * scalar, vector3.y * scalar, vector3.z * scalar);
}

double vector3_magnitude(struct vector3 vector3)
{
    return sqrt(vector3.x * vector3.x + vector3.y * vector3.y + vector3.z * vector3.z);
}

double vector3_dot(struct vector3 vector3, struct vector3 other_vector3)
{
    return vector3.x * other_vector3.x + vector3.y * other_vector3.y + vector3.z * other_vector3.z;
}

struct vector3 vector3_cross(struct vector3 vector3, struct vector3 other_vector3)
{
    return vector3_new(vector3.y * other_vector3.z - vector3.z * other_vector3.y, vector3.z * other_vector3.x - vector3.x * other_vector3.z, vector3.x * other_vector3.y - vector3.y * other_vector3.x);
}