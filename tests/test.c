#include <stdio.h>
#include <stdlib.h>
#include "slac.h"

int test_matrix_contruction() {
	int dims[] = {2, 3};
	int values[] = {1, 6, 2, 0, 5, 3};
	// |1 2 5|
	// |6 0 3|
	matrix* tm = matrix_construct(dims, values);
	free(tm);
	return 1;
}
int test_matrix_multiplication_1() {
	int a_dims[] = {2, 3};
	int b_dims[] = {3, 2};
	int a_values[] = {1, 6, 2, 0, 5, 3};
	// |1 2 5|
	// |6 0 3|
	int b_values[] = {1, 6, 2, 0, 5, 3};
	// |1 0|
	// |6 5|
	// |2 3|

	matrix* a = matrix_construct(a_dims, a_values);
	matrix* b = matrix_construct(b_dims, b_values);
	
	matrix* c = transform(a, b);
	printf("\t\t%d %d\n\t\t", c->dims[0], c->dims[1]);
	for (int i=0; i<c->dims[0]*c->dims[1]; i++)
		printf("%d ", c->values[i]);
	printf("\n");
	
	free(a); free(b);
	return 1;
}
int test_matrix_multiplication_2() {
	int a_dims[] = {3, 3};
	int b_dims[] = {3, 3};
	int a_values[] = {1, 6, 2, 0, 5, 3, 5, 3, 7};
	// |1 0 5|
	// |6 5 3|
	// |2 3 7|
	int b_values[] = {1, 6, 2, 0, 5, 3, 0, 2, 1};
	// |1 0 0|
	// |6 5 2|
	// |2 3 1|

	matrix* a = matrix_construct(a_dims, a_values);
	matrix* b = matrix_construct(b_dims, b_values);
	
	matrix* c = transform(a, b);
	printf("\t\t%d %d\n\t\t", c->dims[0], c->dims[1]);
	for (int i=0; i<c->dims[0]*c->dims[1]; i++)
		printf("%d ", c->values[i]);
	printf("\n");
	
	free(a); free(b);
	return 1;
}

int main() {
	if (test_matrix_contruction())
		printf("\tMATRIX CONSTRUCTION: NOT FAILED\n");
	if (test_matrix_multiplication_1())
		printf("\tMATRIX MULTIPLICATION: NOT FAILED\n");
	if (test_matrix_multiplication_2())
		printf("\tMATRIX MULTIPLICATION: NOT FAILED\n");
	return 0;
}
