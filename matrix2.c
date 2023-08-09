#include "vector2.h"
#include "matrix2.h"
#include <math.h>

struct matrix2 matrix2_identity = (struct matrix2) {(struct vector2) {1, 0}, (struct vector2) {0, 1}};

struct matrix2 matrix2_new(struct vector2 x_vector2, struct vector2 y_vector2)
{
    return (struct matrix2) {x_vector2, y_vector2};
}

double matrix2_determinant(struct matrix2 matrix2)
{
    return vector2_cross(matrix2.x_vector2, matrix2.y_vector2);
}