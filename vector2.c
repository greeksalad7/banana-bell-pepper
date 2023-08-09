#include "vector2.h"
#include "matrix2.h"
#include <math.h>

struct vector2 vector2_zero = (struct vector2) {0, 0};

struct vector2 vector2_new(double x, double y)
{
    return (struct vector2) {x, y};
}

struct vector2 vector2_add(struct vector2 vector2, struct vector2 other_vector2)
{
    return vector2_new(vector2.x + other_vector2.x, vector2.y + other_vector2.y);
}

struct vector2 vector2_subtract(struct vector2 vector2, struct vector2 other_vector2)
{
    return vector2_new(vector2.x - other_vector2.x, vector2.y - other_vector2.y);
}

struct vector2 vector2_multiply(struct vector2 vector2, struct vector2 other_vector2)
{
    return vector2_new(vector2.x * other_vector2.x, vector2.y * other_vector2.y);
}

struct vector2 vector2_multiply_by_scalar(struct vector2 vector2, double scalar)
{
    return vector2_new(vector2.x * scalar, vector2.y * scalar);
}

double vector2_magnitude(struct vector2 vector2)
{
    return sqrt(vector2.x * vector2.x + vector2.y * vector2.y);
}

double vector2_dot(struct vector2 vector2, struct vector2 other_vector2)
{
    return vector2.x * other_vector2.x + vector2.y * other_vector2.y;
}

double vector2_cross(struct vector2 vector2, struct vector2 other_vector2)
{
    return vector2.x * other_vector2.y - vector2.y * other_vector2.x;
}