#ifndef MULTIPLICATIONS_H
#define MULTIPLICATIONS_H

#include "matrix.h"

matrix* transform(matrix* transformation_matrix, matrix* current);
int dot_product(int* a, int* b, int len);

#endif // MULTIPLICATIONS_H 
