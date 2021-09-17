// Chpater 8.3 2

/* Write a program that has a declaration in main() to store the following numbers into an array named rates: 6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0. There should be a function
call to show() that accepts the rates array as a parameter named rates and then displays the numbers in the array*/

#include <stdio.h>


void show(double rate[], const int size) {
	for (int i = 0; i < size; i++) { // array 몇개짜리인지 size 보내줘야 함
		printf("rates (%d) = %f\n", i, rate[i]);
}
	return;
}

int main() {
	double rates[] = {6.5, 8.2, 8.5, 8.3, 8.6,9.4,9.6,9.8,10.0 };
	int rates_size = 9;

	show(rates, rates_size);

	return 0;
}