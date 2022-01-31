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

int main() {
	if (test_matrix_contruction())
		printf("TEST PASSED\n");
	return 0;
}
