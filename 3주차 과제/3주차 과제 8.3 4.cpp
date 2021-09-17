//8.3 4
/* Write a program that declares three one-dimensional arrays named price, quantity and amount. Eaxh array should be declared in main() and should be capable of holding 10 double-precision
numbers. The numbers that should be stored inprice are 10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98. The numbers that should stored in quantity are 4.0, 8.5, 6.0, 8.35,
9.0, 15.3, 3.0, 5.4, 2.9, 4.8. Your program should pass these three arrays to a function called extend(), which should calculate the elements in the amount array as the product of the 
equivalent elements in the price and quantity arrays (for example amount[1] = price[1] * quantity[1]). After extend() has put values in the amount array, the values in the array should be 
displayed from within main()*/

#include <stdio.h>


double extend(const double price[], const double quantity[], int arr_len, double amount[]) {
	int i;
	for (i = 0; i < arr_len; i++) {
		amount[i] = (price[i]) * (quantity[i]);
	}
	return amount[i];
}

#define ARR_LEN 10 // array length

int main() {
	double price[ARR_LEN] = { 10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98 };
	double quantity[ARR_LEN] = { 4.0, 8.5, 6.0, 8.35, 9.0, 15.3, 3.0, 5.4, 2.9, 4.8 };
	double amount[ARR_LEN] = {};

	extend(price, quantity, ARR_LEN, amount);

	for (int i = 0; i < ARR_LEN; i++) {
		printf("Amount(%d) : price(%f) * quauntity(%f) = %f\n", i, price[i], quantity[i], amount[i]);
	}

	printf("\n");

	return 0;
}