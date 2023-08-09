#ifndef MATRIX2_H
#define MATRIX2_H

#include "vector2.h"

struct matrix2
{
    struct vector2 x_vector2;
    struct vector2 y_vector2;
};

extern struct matrix2 matrix2_identity;

struct matrix2 matrix2_new(struct vector2 x_vector2, struct vector2 y_vector2);

double matrix2_determinant(struct matrix2 matrix2);

#endif