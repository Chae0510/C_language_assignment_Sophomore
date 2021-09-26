#include <stdio.h>

struct Car {
	int num;
	int miles;
	int gallons;

} Cars[5] = {
	{25,1450,62}, 
	{36,3240,136}, 
	{44,1792,76},
	{52,2360,105},
	{68,2114,67}
};

int main() {
	double MPG[5]; // miles per gallon
	int total_miles = 0;
	int total_gallons = 0;
	double total_MPG = 0;

	for (int i = 0; i < 5; i++) {
		MPG[i] = double(Cars[i].miles) / double(Cars[i].gallons);
		total_miles += Cars[i].miles;
		total_gallons += Cars[i].gallons;

		printf("Car Number: %d\nMiles per Gallon: %lf\n\n", Cars[i].num, MPG[i]);
	}
	total_MPG = (double)total_miles / (double)total_gallons;

	printf("\nAverage Miles per Gallon(achieved by the five cars): %lf\n", total_MPG);

	return 0;
}