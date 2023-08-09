#ifndef MATRIX3_H
#define MATRIX3_H

#include "vector3.h"

struct matrix3
{
    struct vector3 x_vector3;
    struct vector3 y_vector3;
    struct vector3 z_vector3;
};

extern struct matrix3 matrix3_identity;
extern struct matrix3 matrix3_zero;

struct matrix3 matrix3_new(struct vector3 x_vector3, struct vector3 y_vector3, struct vector3 z_vector3);

struct vector3 matrix3_transform_vector3(struct matrix3 matrix3, struct vector3 vector3);
struct matrix3 matrix3_multiply(struct matrix3 matrix3, struct matrix3 other_matrix3);
struct matrix3 matrix3_adjoint(struct matrix3 matrix3);
struct matrix3 matrix3_inverse(struct matrix3 matrix3);
struct matrix3 matrix3_cofactor(struct matrix3 matrix3);
double matrix3_determinant(struct matrix3 matrix3);

#endif