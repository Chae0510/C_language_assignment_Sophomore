// 9.4
/* Write a C function named licquid() that is to accept an integer number and the addresses of the variables gallons, quarts, pints, and cups. The passed integer represents the total number of cups, and function is to determine the number of gallons, quarts, pints, and cups in the passed value. Using the passed addresses, the function should directly alter the respective variables in the calling funcion. Use the relationships of 2 cups to a pint, 4 cups to a quart, and 16 cups to a gallon.
 */

#include <stdio.h>
#include <math.h>


void liquid(int num, double* gallons, double* quarts, double* pints, int* cups) {

	*cups = num;
	*pints = ceil(0.5 * *cups);
	*quarts = ceil(0.25 * *cups); 
	*gallons = ceil(0.0625 * *cups); 
}

int main() {
	// inout
	int num=4, cups;
	double gallons, quarts, pints;



	// liquid()
	liquid(num, &gallons, &quarts, &pints, &cups);

	//print out
	printf("num(%d) --> (%f) Gallons, (%f) Quarts, (%f) Pints, (%d) Cups", num, gallons, quarts, pints, cups);


}
