#ifndef VECTOR3_H
#define VECTOR3_H

struct vector3
{
    double x;
    double y;
    double z;
};

extern struct vector3 vector3_zero;

struct vector3 vector3_new(double x, double y, double z);

struct vector3 vector3_add(struct vector3 vector3, struct vector3 other_vector3);
struct vector3 vector3_subtract(struct vector3 vector3, struct vector3 other_vector3);
struct vector3 vector3_multiply(struct vector3 vector3, struct vector3 other_vector3);
struct vector3 vector3_multiply_by_scalar(struct vector3 vector3, double scalar);
double vector3_magnitude(struct vector3 vector3);
double vector3_dot(struct vector3 vector3, struct vector3 other_vector3);
struct vector3 vector3_cross(struct vector3 vector3, struct vector3 other_vector3);

#endif