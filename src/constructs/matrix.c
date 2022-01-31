#include <malloc.h>
#include "matrix.h"

// the matricies are built as column vector sets
// however they can be read as a set of rows or a
// 	set of colums
matrix* matrix_construct(int* dims, int* values) {
	matrix* new_matrix = (matrix*)malloc(sizeof(matrix));
	if (new_matrix) {
		new_matrix->dims = dims;
		new_matrix->values = values;
	}
	return new_matrix;
}

void matrix_kill(matrix* matrix) {
	free(matrix->dims);		matrix->dims = NULL;
	free(matrix->values);	matrix->values = NULL;
	free(matrix);			matrix = NULL;
}
