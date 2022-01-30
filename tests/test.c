#include <stdio.h>
#include "slac.h"

int main() {
	printf("why am i doing this\n");
	if (slac_init() == 0)
		printf("at least it works\n");
	return 0;
}
