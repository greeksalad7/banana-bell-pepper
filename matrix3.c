#include "vector3.h"
#include "matrix3.h"
#include "matrix2.h"
#include "vector2.h"
#include <math.h>

struct matrix3 matrix3_identity = (struct matrix3) {(struct vector3) {1, 0, 0}, (struct vector3) {0, 1, 0}, (struct vector3) {0, 0, 1}};
struct matrix3 matrix3_zero = (struct matrix3) {(struct vector3) {0, 0, 0}, (struct vector3) {0, 0, 0}, (struct vector3) {0, 0, 0}};

struct matrix3 matrix3_new(struct vector3 x_vector3, struct vector3 y_vector3, struct vector3 z_vector3)
{
    return (struct matrix3) {x_vector3, y_vector3, z_vector3};
}

struct vector3 matrix3_transform_vector3(struct matrix3 matrix3, struct vector3 vector3)
{
    return vector3_add(vector3_add(vector3_multiply_by_scalar(matrix3.x_vector3, vector3.x), vector3_multiply_by_scalar(matrix3.y_vector3, vector3.y)), vector3_multiply_by_scalar(matrix3.z_vector3, vector3.z));
}

struct matrix3 matrix3_transform(struct matrix3 matrix3, struct matrix3 other_matrix3)
{
    return
        matrix3_new(
            matrix3_transform_vector3(matrix3, other_matrix3.x_vector3),
            matrix3_transform_vector3(matrix3, other_matrix3.y_vector3),
            matrix3_transform_vector3(matrix3, other_matrix3.z_vector3)
        );
}

struct matrix3 matrix3_adjoint(struct matrix3 matrix3)
{
    return
        matrix3_new(
            vector3_new(matrix3.x_vector3.x, matrix3.y_vector3.x, matrix3.z_vector3.x),
            vector3_new(matrix3.x_vector3.y, matrix3.y_vector3.y, matrix3.z_vector3.y),
            vector3_new(matrix3.x_vector3.z, matrix3.y_vector3.z, matrix3.z_vector3.z)
        );
}

struct matrix3 matrix3_cofactor(struct matrix3 matrix3)
{
    struct matrix2 minor_matrix2;
    struct matrix3 cofactor_matrix3;

    minor_matrix2.x_vector2.x = matrix3.y_vector3.y;
    minor_matrix2.x_vector2.y = matrix3.y_vector3.z;
    minor_matrix2.y_vector2.x = matrix3.z_vector3.y;
    minor_matrix2.y_vector2.y = matrix3.z_vector3.z;

    cofactor_matrix3.x_vector3.x = matrix2_determinant(minor_matrix2);

    minor_matrix2.x_vector2.x = matrix3.y_vector3.x;
    minor_matrix2.x_vector2.y = matrix3.y_vector3.z;
    minor_matrix2.y_vector2.x = matrix3.z_vector3.x;
    minor_matrix2.y_vector2.y = matrix3.z_vector3.z;

    cofactor_matrix3.x_vector3.y = -matrix2_determinant(minor_matrix2);

    minor_matrix2.x_vector2.x = matrix3.y_vector3.x;
    minor_matrix2.x_vector2.y = matrix3.y_vector3.y;
    minor_matrix2.y_vector2.x = matrix3.z_vector3.x;
    minor_matrix2.y_vector2.y = matrix3.z_vector3.y;

    cofactor_matrix3.x_vector3.z = matrix2_determinant(minor_matrix2);

    minor_matrix2.x_vector2.x = matrix3.x_vector3.y;
    minor_matrix2.x_vector2.y = matrix3.x_vector3.z;
    minor_matrix2.y_vector2.x = matrix3.z_vector3.y;
    minor_matrix2.y_vector2.y = matrix3.z_vector3.z;

    cofactor_matrix3.y_vector3.x = -matrix2_determinant(minor_matrix2);

    minor_matrix2.x_vector2.x = matrix3.x_vector3.x;
    minor_matrix2.x_vector2.y = matrix3.x_vector3.z;
    minor_matrix2.y_vector2.x = matrix3.z_vector3.x;
    minor_matrix2.y_vector2.y = matrix3.z_vector3.z;

    cofactor_matrix3.y_vector3.y = matrix2_determinant(minor_matrix2);

    minor_matrix2.x_vector2.x = matrix3.x_vector3.x;
    minor_matrix2.x_vector2.y = matrix3.x_vector3.y;
    minor_matrix2.y_vector2.x = matrix3.z_vector3.x;
    minor_matrix2.y_vector2.y = matrix3.z_vector3.y;

    cofactor_matrix3.y_vector3.z = -matrix2_determinant(minor_matrix2);

    minor_matrix2.x_vector2.x = matrix3.x_vector3.y;
    minor_matrix2.x_vector2.y = matrix3.x_vector3.z;
    minor_matrix2.y_vector2.x = matrix3.y_vector3.y;
    minor_matrix2.y_vector2.y = matrix3.y_vector3.z;

    cofactor_matrix3.z_vector3.x = matrix2_determinant(minor_matrix2);

    minor_matrix2.x_vector2.x = matrix3.x_vector3.x;
    minor_matrix2.x_vector2.y = matrix3.x_vector3.z;
    minor_matrix2.y_vector2.x = matrix3.y_vector3.x;
    minor_matrix2.y_vector2.y = matrix3.y_vector3.z;

    cofactor_matrix3.z_vector3.y = -matrix2_determinant(minor_matrix2);

    minor_matrix2.x_vector2.x = matrix3.x_vector3.x;
    minor_matrix2.x_vector2.y = matrix3.x_vector3.y;
    minor_matrix2.y_vector2.x = matrix3.y_vector3.x;
    minor_matrix2.y_vector2.y = matrix3.y_vector3.y;

    cofactor_matrix3.z_vector3.z = matrix2_determinant(minor_matrix2);

    return cofactor_matrix3;
}

double matrix3_determinant(struct matrix3 matrix3)
{
    struct matrix3 adjoint_matrix3 = matrix3_adjoint(matrix3);

    return vector3_dot(adjoint_matrix3.x_vector3, vector3_cross(adjoint_matrix3.y_vector3, adjoint_matrix3.z_vector3));
}

struct matrix3 matrix3_multiply_by_scalar(struct matrix3 matrix3, double scalar)
{
    return
        matrix3_new(
            vector3_multiply_by_scalar(matrix3.x_vector3, scalar),
            vector3_multiply_by_scalar(matrix3.y_vector3, scalar),
            vector3_multiply_by_scalar(matrix3.z_vector3, scalar)
        );
}

struct matrix3 matrix3_inverse(struct matrix3 matrix3)
{
    return
        matrix3_multiply_by_scalar(
            matrix3_adjoint(
                matrix3_cofactor(matrix3)
            ),
            1 / matrix3_determinant(matrix3)
        );
}