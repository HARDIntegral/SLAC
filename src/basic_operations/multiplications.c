#include "multiplications.h"

matrix* transform(matrix* transformation_matrix, matrix* current) {
	// determine if multiplication is defined
	if (transformation_matrix->dims[1] != current->dims[0])
		return NULL;

	// calculate new dims
	int* new_dims = (int*)malloc(sizeof(int) * 2);
	new_dims[0] = transformation_matrix->dims[0];
	new_dims[1] = current->dims[1];

	// calculate new matrix values
	int* new_vals = (int*)malloc(sizeof(int) * new_dims[0] * new_dims[1]);
	int* tmp_row = (int*)malloc(sizeof(int)*transformation_matrix->dims[0]);
	int* tmp_col = (int*)malloc(sizeof(int)*current->dims[1]);
	int c;		// current column
	int r;		// current row

	for(int i=0; i<new_dims[0]*new_dims[1]; i++) {
		c = i/new_dims[0];
		r = i%new_dims[0];

		// extracting a column
		for (int i=0; i<current->dims[0]; i++)
			tmp_col[i] = current->values[i+(c*current->dims[0])];
		// extracting a row
		for (int i=0; i<transformation_matrix->dims[1]; i++)
			tmp_row[i] = transformation_matrix->values[r+i*transformation_matrix->dims[0]];

		new_vals[i] = dot_product(tmp_row, tmp_col, current->dims[1]);
	}

	free(tmp_row);	tmp_row=NULL;
	free(tmp_col);	tmp_col=NULL;

	return matrix_construct(new_dims, new_vals);
}

int dot_product(int* a, int* b, int len) {
	int result = 0;
	for (int i=0; i<len; i++)
		result += a[i]*b[i];
	return result;
}
