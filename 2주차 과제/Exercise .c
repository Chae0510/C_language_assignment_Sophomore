#include <stdio.h>

void calculate(int* n1, int* n2, int* re1, int* re2, int* re3, int* re4) {
	*re1 = *n1 * *n2;

	if (*n2 == 0) {
		printf("Error : Cannot Divide by zero !!");
		*re2 = 0;
		*re3 = 0;
	}
	else {
		*re2 = *n1 / *n2;
		*re3 = *n1 % *n2;
	}
	re4 = *n1 + *n2;
}

int main() {
	// -- input
	int N1[] = { 10,10,9999,-1000 };
	int N2[] = { 5,0,-99,2 };
	int times = 4;
	int re1, re2, re3, re4;

	for (int i = 0; i < times; i++) {
		printf("\n //--Experiment (%d)\n", i);
		int n1 = N1[i];
		int n2 = N2[i];

		// -- calculat ()
		calculate(&n1, &n2, &re1, &re2, &re3, &re4);

		// -- print out
		printf("%d * %d = %d\n", n1, n2, re1);
		printf("%d / %d = %d\n", n1, n2, re2);
		printf("%d %% %d = %d\n", n1, n2, re3);
		printf("%d + %d = %d\n", n1, n2, re4);
	}
	

	return 0;
}