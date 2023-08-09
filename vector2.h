#ifndef VECTOR2_H
#define VECTOR2_H

struct vector2
{
    double x;
    double y;
};

extern struct vector2 vector2_zero;

struct vector2 vector2_new(double x, double y);

struct vector2 vector2_add(struct vector2 vector2, struct vector2 other_vector2);
struct vector2 vector2_subtract(struct vector2 vector2, struct vector2 other_vector2);
struct vector2 vector2_multiply(struct vector2 vector2, struct vector2 other_vector2);
struct vector2 vector2_multiply_by_scalar(struct vector2 vector2, double scalar);
double vector2_magnitude(struct vector2 vector2);
double vector2_dot(struct vector2 vector2, struct vector2 other_vector2);
double vector2_cross(struct vector2 vector2, struct vector2 other_vector2);

#endif