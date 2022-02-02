#ifndef MATRIX_H
#define MATRIX_H

#include <malloc.h>

typedef struct matrix {
	int* dims; 
	int* values;
} matrix;

matrix* matrix_construct(int* dims, int* values);
void matrix_kill(matrix* matrix);

#endif // MATRIX_H
