#include<stdio.h>
struct Date {
	int day;
	int month;
	int year;
};

struct Date recent(struct Date d1, struct Date d2) {
	

	if (d2.year > d1.year)
		return d2;
	else
	{
		if (d1.year > d2.year)
			return d1;
		else 
		{
			if (d2.month > d1.month)
				return d2;
			else
			{
				if (d1.month > d2.month)
					return d1;
				else 
				{
					if (d2.day > d1.day)
						return d2;
					else
						return d1;
				}
			}
		}
	}
	
}

int main(Date d3) {	

	struct Date d1[] = {
	{05,10,2001},
	{8,29,1999},
	{07,18,1972},
	{05,03,1966},
	{03,24,2021}
	};

	struct Date d2[] = {
	{04,29,2000},
	{07,23,2008},
	{06,21,1998},
	{9,13,1996},
	{05,12,2004}
	};

	for (int i = 0; i < 5; i++) {
		struct Date d3 = recent(d1[i], d2[i]);
		Days(d1[i], d2[i]);
		printf("The larger date is %d / %d / %d\n ", d3.day, d3.month, d3.year); 

	}


	
	return 0;
}

