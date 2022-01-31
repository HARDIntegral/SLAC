#include <stdio.h>
#include "slac.h"

int test_matrix_contruction() {
	int dims[] = {2, 3};
	int values[] = {1, 6, 2, 0, 5, 3};
	// |1 2 5|
	// |6 0 3|
	matrix_kill(matrix_construct(dims, values));
	return 1;
}

int main() {
	if (test_matrix_contruction())
		printf("TEST PASSED\n");
	return 0;
}
